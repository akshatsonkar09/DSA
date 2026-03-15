// /*****************************************************************
//  DATA STRUCTURE LAB – ASSIGNMENT 1
//  CSN12101 – MNNIT ALLAHABAD
//  NOTE:
//  • Each question has its OWN main().
//  • Compile and run ONE program at a time by commenting others.
// *****************************************************************/

// /*===============================================================
//  1. Sum of Divisors & Perfect Numbers
// ===============================================================*/
// #include <stdio.h>
// int sum_of_divisor(int n) {
//     int sum = 0;
//     for (int i = 1; i <= n / 2; i++)
//         if (n % i == 0)
//             sum += i;
//     return sum;
// }

// int main() {
//     int low, high;
// printf("Enter the low and high\n");
//     scanf("%d %d", &low, &high);
//     for (int i = low; i <= high; i++)
//         if (sum_of_divisor(i) == i)
//             printf("%d ", i);
//     return 0;
// }


// /*===============================================================
//  2. Binary Equivalent Using Recursion
// ===============================================================*/
// #include <stdio.h>

// void binary(int n) {
//     if (n == 0) return;
//     binary(n / 2);
//     printf("%d", n % 2);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     if (n == 0) printf("0");
//     else binary(n);
//     return 0;
// }

// /*===============================================================
//  3. Decimal to Any Base
// ===============================================================*/
// #include <stdio.h>

// void convert(int n, int base) {
//     char d[] = "0123456789ABCDEF";
//     if (n == 0) return;
//     convert(n / base, base);
//     printf("%c", d[n % base]);
// }

// int main() {
//     int n, base;
//     scanf("%d %d", &n, &base);
//     if (n == 0) printf("0");
//     else convert(n, base);
//     return 0;
// }

// /*===============================================================
//  4. Matrix Addition & Subtraction
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int row, col;
//     scanf("%d %d", &row, &col);
//     int a[row][col], b[row][col];

//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             scanf("%d", &a[i][j]);

//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             scanf("%d", &b[i][j]);

//     printf("Addition:\n");
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++)
//             printf("%d ", a[i][j] + b[i][j]);
//         printf("\n");
//     }

//     printf("Subtraction:\n");
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++)
//             printf("%d ", a[i][j] - b[i][j]);
//         printf("\n");
//     }
//     return 0;
// }

// /*===============================================================
//  5. Matrix Multiplication
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int row1, col1, row2, col2;
//     scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

//     if (col1 != row2) {
//         printf("Not possible");
//         return 0;
//     }

//     int a[row1][col1], b[row2][col2], c[row1][col2];

//     for (int i = 0; i < row1; i++)
//         for (int j = 0; j < col1; j++)
//             scanf("%d", &a[i][j]);

//     for (int i = 0; i < row2; i++)
//         for (int j = 0; j < col2; j++)
//             scanf("%d", &b[i][j]);

//     for (int i = 0; i < row1; i++)
//         for (int j = 0; j < col2; j++) {
//             c[i][j] = 0;
//             for (int k = 0; k < col1; k++)
//                 c[i][j] += a[i][k] * b[k][j];
//         }

//     for (int i = 0; i < row1; i++) {
//         for (int j = 0; j < col2; j++)
//             printf("%d ", c[i][j]);
//         printf("\n");
//     }
//     return 0;
// }

// /*===============================================================
//  6. Upper & Lower Triangular Matrix
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);
//     int a[n][n];

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             scanf("%d", &a[i][j]);

//     printf("Lower:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//             printf("%d ", (i >= j) ? a[i][j] : 0);
//         printf("\n");
//     }

//     printf("Upper:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//             printf("%d ", (i <= j) ? a[i][j] : 0);
//         printf("\n");
//     }
//     return 0;
// }

// /*===============================================================
//  7. Structure with Pointer
// ===============================================================*/
// #include <stdio.h>

// struct Student {
//     int roll;
//     char name[30];
//     float marks;
// };

// int main() {
//     struct Student s;
//     struct Student *p = &s;
//     scanf("%d %s %f", &p->roll, p->name, &p->marks);
//     printf("%d %s %.2f", p->roll, p->name, p->marks);
//     return 0;
// }

// /*===============================================================
//  8. Binary File Employee Database
// ===============================================================*/
// #include <stdio.h>

// struct Employee {
//     int id;
//     char name[40];
//     double salary;
//     int active;
// };

// int main() {
//     FILE *fp = fopen("emp.dat", "ab");
//     struct Employee e;
//     scanf("%d %s %lf", &e.id, e.name, &e.salary);
//     e.active = 1;
//     fwrite(&e, sizeof(e), 1, fp);
//     fclose(fp);
//     return 0;
// }

// /*===============================================================
//  9. Memory Pool Allocator
// ===============================================================*/
// #include <stdio.h>

// #define BLOCK_SIZE 32
// #define POOL_SIZE 10

// typedef union Block {
//     struct { union Block *next; } freeNode;
//     char payload[BLOCK_SIZE];
// } Block;

// Block pool[POOL_SIZE];
// Block *freeList;

// void init_pool() {
//     for (int i = 0; i < POOL_SIZE - 1; i++)
//         pool[i].freeNode.next = &pool[i + 1];
//     pool[POOL_SIZE - 1].freeNode.next = NULL;
//     freeList = &pool[0];
// }

// /*===============================================================
//  10. Smallest Missing Positive Number
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int a[] = {2,3,7,6,8,-1,-10,15};
//     int present[100] = {0};

//     for (int i = 0; i < 8; i++)
//         if (a[i] > 0 && a[i] < 100)
//             present[a[i]] = 1;

//     for (int i = 1; i < 100; i++)
//         if (!present[i]) {
//             printf("%d", i);
//             break;
//         }
//     return 0;
// }

// /*===============================================================
//  11. Copy Array Using Pointers & Dynamic Memory
// ===============================================================*/
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("Hello World\n");
//     int n;
//     scanf("%d", &n);

//     int *a = malloc(n * sizeof(int));
//     int *b = malloc(n * sizeof(int));

//     for (int i = 0; i < n; i++)
//         scanf("%d", a + i);

//     for (int i = 0; i < n; i++)
//         *(b + i) = *(a + i);

//     printf("Copied successfully");
//     return 0;
// }

// /*===============================================================
//  12. Return Multiple Values Using Pointers
// ===============================================================*/
// #include <stdio.h>

// void calc(int a, int b, int *sum, int *diff) {
//     *sum = a + b;
//     *diff = a - b;
// }

// int main() {
//     int s, d;
//     calc(10, 5, &s, &d);
//     printf("%d %d", s, d);
//     return 0;
// }

// /*===============================================================
//  13. Linear Search
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int n, key;
//     scanf("%d", &n);
//     int a[n];
//     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//     scanf("%d", &key);

//     for (int i = 0; i < n; i++)
//         if (a[i] == key) {
//             printf("Found at %d", i);
//             return 0;
//         }
//     printf("Not found");
//     return 0;
// }

// /*===============================================================
//  14. Binary Search
// ===============================================================*/
// #include <stdio.h>

// int main() {
//     int n, key;
//     scanf("%d", &n);
//     int a[n];
//     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//     scanf("%d", &key);

//     int l = 0, r = n - 1;
//     while (l <= r) {
//         int m = (l + r) / 2;
//         if (a[m] == key) {
//             printf("Found at %d", m);
//             return 0;
//         } else if (a[m] < key)
//             l = m + 1;
//         else
//             r = m - 1;
//     }
//     printf("Not found");
//     return 0;
// }

// /*===============================================================
//  15. Bubble Sort with Comparisons & Time
// ===============================================================*/
#include <stdio.h>

int main() {
    int n, comp = 0;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);


    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }


    return 0;
}
