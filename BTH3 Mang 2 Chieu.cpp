#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}


void findMinMax(int m, int n, int **mat, int *max, int *min) {
    *max = mat[0][0];
    *min = mat[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > *max) {
                *max = mat[i][j];
            }
            if (mat[i][j] < *min) {
                *min = mat[i][j];
            }
        }
    }
}


void countAndSumPrimes(int m, int n, int **mat, int *count, int *sum) {
    *count = 0;
    *sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(mat[i][j])) {
                (*count)++;
                (*sum) += mat[i][j];
            }
        }
    }
}


int main() {
    int m, n;

    printf("1. Nhap so dong cua ma tran: ");
    scanf("%d", &m);
    printf("   Nhap so cot cua ma tran: ");
    scanf("%d", &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    printf("2. Nhap ma tran %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("   a[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("3. Ma tran vua nhap theo dong cot:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

