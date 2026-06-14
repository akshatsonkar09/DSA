/*
 * keep_lines.c
 *
 * Usage: keep_lines <file>
 *
 * Keeps lines 1,2,7,8 of each 8-line block in the given file.
 * Creates a backup at <file>.bak and edits the file in-place.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *read_line(FILE *f) {
    size_t cap = 128;
    size_t len = 0;
    char *buf = malloc(cap);
    if (!buf) return NULL;
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (len + 1 >= cap) {
            cap *= 2;
            char *tmp = realloc(buf, cap);
            if (!tmp) { free(buf); return NULL; }
            buf = tmp;
        }
        buf[len++] = (char)c;
        if (c == '\n') break;
    }
    if (len == 0 && feof(f)) { free(buf); return NULL; }
    buf[len] = '\0';
    return buf;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 2;
    }
    const char *path = argv[1];

    FILE *in = fopen(path, "rb");
    if (!in) { perror("open input"); return 3; }

    /* create backup */
    size_t L = strlen(path) + 8;
    char *bak = malloc(L);
    if (!bak) { fclose(in); return 4; }
    snprintf(bak, L, "%s.bak", path);
    FILE *outbak = fopen(bak, "wb");
    if (!outbak) { perror("create backup"); free(bak); fclose(in); return 5; }
    char buf[4096];
    size_t r;
    while ((r = fread(buf, 1, sizeof(buf), in)) > 0) {
        if (fwrite(buf, 1, r, outbak) != r) { perror("write backup"); fclose(in); fclose(outbak); free(bak); return 6; }
    }
    fclose(outbak);
    fclose(in);

    /* reopen for text processing */
    in = fopen(path, "r");
    if (!in) { perror("reopen input"); free(bak); return 7; }

    char *tmpname = malloc(L);
    if (!tmpname) { fclose(in); free(bak); return 8; }
    snprintf(tmpname, L, "%s.tmp", path);
    FILE *tmp = fopen(tmpname, "w");
    if (!tmp) { perror("open temp"); fclose(in); free(bak); free(tmpname); return 9; }

    long lineno = 0;
    char *line;
    while ((line = read_line(in)) != NULL) {
        int mod = (int)(lineno % 8);
        if (mod == 0 || mod == 1 || mod == 6 || mod == 7) {
            fputs(line, tmp);
        }
        lineno++;
        free(line);
    }

    fclose(in);
    fclose(tmp);

    /* replace original with temp */
    if (remove(path) != 0) {
        perror("remove original");
        /* leave backup and temp in place */
        free(bak);
        free(tmpname);
        return 10;
    }
    if (rename(tmpname, path) != 0) {
        perror("rename temp");
        free(bak);
        free(tmpname);
        return 11;
    }

    printf("Processed '%s' — backup at '%s'\n", path, bak);
    free(bak);
    free(tmpname);
    return 0;
}
