#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SinhVien {
    char Masv[10];
    char Hotensv[30];
    char Phai[10];
    int Namsinh;
    char Nganhhoc[30];
    float Kqcuoikhoa;
    char Xeploai[20];
    char Quequan[30];
};

typedef struct SinhVien SINHVIEN;

void Nhapsv(SINHVIEN *x) {
    fflush(stdin);
    printf("Nhap Ma SV: ");
    gets(x->Masv);
    fflush(stdin);
    printf("Nhap ho ten: ");
    gets(x->Hotensv);
    fflush(stdin);
    printf("Nhap phai: ");
    gets(x->Phai);
    fflush(stdin);
    printf("Nhap Nganh hoc: ");
    gets(x->Nganhhoc);
    fflush(stdin);
    printf("Nhap Que quan: ");
    gets(x->Quequan);

    do {
        printf("Nhap Nam sinh: ");
        scanf("%d", &x->Namsinh);
    } while (x->Namsinh < 1980 || x->Namsinh > 2010);

    do {
        printf("Nhap KQ cuoi khoa: ");
        scanf("%f", &x->Kqcuoikhoa);
    } while (x->Kqcuoikhoa < 0 || x->Kqcuoikhoa > 4);

    if (x->Kqcuoikhoa <= 1.5) {
        strcpy(x->Xeploai, "Yeu");
    } else if (x->Kqcuoikhoa <= 2.5) {
        strcpy(x->Xeploai, "Trung binh");
    } else if (x->Kqcuoikhoa <= 3.0) {
        strcpy(x->Xeploai, "Kha");
    } else if (x->Kqcuoikhoa <= 3.8) {
        strcpy(x->Xeploai, "Gioi");
    } else {
        strcpy(x->Xeploai, "Xuat sac");
    }
}

void NhapsvN(SINHVIEN a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d\n", i + 1);
        Nhapsv(&a[i]);
    }
}

void Xuatsv(SINHVIEN x) {
    printf("%-10s|%-30s|%-10s|%4d|%-30s|%12.1f|%-20s|%-30s|\n",
           x.Masv, x.Hotensv, x.Phai, x.Namsinh, x.Nganhhoc, x.Kqcuoikhoa, x.Xeploai, x.Quequan);
}

void XuatsvN(SINHVIEN a[], int n) {
    system("cls");

    printf("\n|----------------------------------------------------------------------------------------\n");
    printf("|Ma SV    | Ho ten sinh vien                  | Phai     | Nam sinh | Nganh hoc            | KQ cuoi khoa | Xep loai        | Que quan                   |\n");
    for (int i = 0; i < n; i++) {
        printf("|---------|----------------------------------|----------|----------|---------------------|--------------|-----------------|----------------------------|\n");
        Xuatsv(a[i]);
    }
}

void Sapxep(SINHVIEN a[], int n) {
    SINHVIEN tmp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].Kqcuoikhoa > a[j].Kqcuoikhoa) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void Timsv(SINHVIEN a[], int n) {
    system("cls");
    printf("|----------------------------------------------------------------------------------------\n");
    printf("|Ma SV    | Ho ten sinh vien                  | Phai     | Nam sinh | Nganh hoc            | KQ cuoi khoa | Xep loai        | Que quan                   |\n");
    for (int i = 0; i < n; i++) {
        if (a[i].Kqcuoikhoa >= 3.0) {
            printf("|---------|----------------------------------|----------|----------|---------------------|--------------|-----------------|----------------------------|\n");
            Xuatsv(a[i]);
        }
    }
}

int main() {
    int n;
    SINHVIEN a[10];

    printf("\nNhap so luong sinh vien: ");
    scanf("%d", &n);

    NhapsvN(a, n);

    while (1) {
        system("cls");

        printf("**************************************************\n");
        printf("**        CHUONG TRINH QUAN LY SINH VIEN        **\n");
        printf("**        1. Nhap DS sinh vien                  **\n");
        printf("**        2. In danh sach sinh vien             **\n");
        printf("**        3. Sap xep theo Kq cuoikhoa           **\n");
        printf("**        4. In sinh vien Gioi, Xuat sac        **\n");
        printf("**        5. Tim kiem sinh vien theo MASV       **\n");
        printf("**        0. Thoat                              **\n");
        printf("**************************************************\n");

        int choice;
        printf("\n\t\t      CHON CHUC NANG: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\nNHAP SO LUONG SINH VIEN: ");
                    scanf("%d", &n);
                } while (n <= 0);

                NhapsvN(a, n);
                printf("\nBam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;

            case 2:
                XuatsvN(a, n);
                printf("\nBam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;

            case 3:
                Sapxep(a, n);
                XuatsvN(a, n);
                printf("\nBam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;

            case 4:
                Timsv(a, n);
                printf("\nBam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;

            case 5:
                char MasvTim[10];
                printf("\nNhap Ma SV can tim: ");
                scanf("%s", MasvTim);
                for (int i = 0; i < n; i++) {
                    if (strcmp(a[i].Masv, MasvTim) == 0) {
                        system("cls");
                        printf("|----------------------------------------------------------------------------------------\n");
                        printf("|Ma SV    | Ho ten sinh vien                  | Phai     | Nam sinh | Nganh hoc            | KQ cuoi khoa | Xep loai        | Que quan                   |\n");
                        printf("|---------|----------------------------------|----------|----------|---------------------|--------------|-----------------|----------------------------|\n");
                        Xuatsv(a[i]);
                        break;
                    }
                }
                printf("\nBam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;

            case 0:
                exit(0);

            default:
                printf("Khong co chuc nang nay!\n");
                printf("Bam Enter de tiep tuc...");
                while (getchar() != '\n');
                getchar();
                break;
        }
    }

    return 0;
}

