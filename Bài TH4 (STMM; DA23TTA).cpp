#include <stdio.h>


void nhapMaTran(int m, int n, int matran[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap gia tri cho phan tu matran[%d][%d]: ", i, j);
            scanf("%d", &matran[i][j]);
        }
    }
}


void xuatMaTran(int m, int n, int matran[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matran[i][j]);
        }
        printf("\n");
    }
}


int timMax(int m, int n, int matran[][100]) {
    int max = matran[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matran[i][j] > max) {
                max = matran[i][j];
            }
        }
    }
    return max;
}


int timMin(int m, int n, int matran[][100]) {
    int min = matran[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matran[i][j] < min) {
                min = matran[i][j];
            }
        }
    }
    return min;
}


int laSNT(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}


void demVaTinhTongSNT(int m, int n, int matran[][100], int *dem, int *tong) {
    *dem = 0;
    *tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSNT(matran[i][j])) {
                (*dem)++;
            }
            (*tong) += matran[i][j];
        }
    }
}


void timVaInViTriX(int m, int n, int matran[][100], int x) {
    printf("Cac vi tri cua %d tren ma tran:\n", x);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matran[i][j] == x) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}


int laDiemYenNgua(int m, int n, int matran[][100], int row, int col) {
    int minDong = matran[row][col];
    int maxCot = matran[row][col];
    for (int i = 0; i < n; i++) {
        if (matran[row][i] < minDong) {
            minDong = matran[row][i];
        }
    }
    for (int j = 0; j < m; j++) {
        if (matran[j][col] > maxCot) {
            maxCot = matran[j][col];
        }
    }
    return (minDong == matran[row][col] && maxCot == matran[row][col]);
}


void inDiemYenNgua(int m, int n, int matran[][100]) {
    printf("Cac diem yen ngua tren ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laDiemYenNgua(m, n, matran, i, j)) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}


void sapXepTangDan(int m, int n, int matran[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                for (int q = 0; q < n; q++) {
                    if (matran[i][j] < matran[p][q]) {
                        int temp = matran[i][j];
                        matran[i][j] = matran[p][q];
                        matran[p][q] = temp;
                    }
                }
            }
        }
    }
}


int tongDuongCheoChinh(int m, int n, int matran[][100]) {
    int sum = 0;
    for (int i = 0; i < m && i < n; i++) {
        sum += matran[i][i];
    }
    return sum;
}


int demSoChanTamGiacTren(int m, int n, int matran[][100]) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matran[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}


void timVaInSoLeTamGiacDuoi(int m, int n, int matran[][100]) {
    printf("Cac so le nam trong tam giac duoi cua duong cheo phu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && (i + j) < (m - 1)) {
                if (matran[i][j] % 2 != 0) {
                    printf("%d\t", matran[i][j]);
                }
            }
        }
    }
}


void nhapTinhTongHaiMaTran(int m, int n, int A[][100], int B[][100], int C[][100]) {
    printf("Nhap ma tran A:\n");
    nhapMaTran(m, n, A);
    printf("Nhap ma tran B:\n");
    nhapMaTran(m, n, B);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Ma tran tong C:\n");
    xuatMaTran(m, n, C);
}


void tinhTichHaiMaTran(int m, int n, int p, int A[][100], int B[][100], int C[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, n;
    printf("Nhap so dong (m): ");
    scanf("%d", &m);
    printf("Nhap so cot (n): ");
    scanf("%d", &n);

    int matran[100][100];
    nhapMaTran(m, n, matran);

    printf("Ma tran vua nhap:\n");
    xuatMaTran(m, n, matran);

    int max = timMax(m, n, matran);
    int min = timMin(m, n, matran);

    printf("Phan tu lon nhat trong ma tran: %d\n", max);
    printf("Phan tu nho nhat trong ma tran: %d\n", min);

    int demSNT, tongSNT;
    demVaTinhTongSNT(m, n, matran, &demSNT, &tongSNT);
    printf("So phan tu nguyen to trong ma tran: %d\n", demSNT);
    printf("Tong cac phan tu tren ma tran: %d\n", tongSNT);

    int x;
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    timVaInViTriX(m, n, matran, x);

    inDiemYenNgua(m, n, matran);

    sapXepTangDan(m, n, matran);
    printf("Ma tran sau khi sap xep tang dan:\n");
    xuatMaTran(m, n, matran);

    int tongDuongCheo = tongDuongCheoChinh(m, n, matran);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongDuongCheo);

    int soChanTamGiacTren = demSoChanTamGiacTren(m, n, matran);
    printf("So so chan nam trong tam giac tren cua duong cheo chinh: %d\n", soChanTamGiacTren);

    timVaInSoLeTamGiacDuoi(m, n, matran);

    int A[100][100], B[100][100], C[100][100];
    int p;
    printf("Nhap so cot cho ma tran B (p): ");
    scanf("%d", &p);

    nhapTinhTongHaiMaTran(m, n, A, B, C);

    printf("Nhap so dong cho ma tran B (p): ");
    scanf("%d", &p);

    tinhTichHaiMaTran(m, n, p, A, B, C);

    printf("Ma tran tich C:\n");
    xuatMaTran(m, p, C);

    return 0;
}

