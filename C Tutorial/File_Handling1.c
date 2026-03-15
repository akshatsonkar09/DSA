#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *fptrs, *fptrd;

fptrs = fopen("file.txt","r");
fptrd = fopen("file1.txt","w");

int ch;
ch = fgetc(fptrs);

while (ch != EOF) {
    fputc(ch,fptrd);
    ch = fgetc(fptrs);
}
return 0;
}