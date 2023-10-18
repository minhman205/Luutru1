#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>  // Thêm thu vi?n conio.h
#include <stdbool.h>

void nhapChuoi(char s[], const char* prompt) {
    printf("%s: ", prompt);
    fflush(stdin);
    gets(s);
}

void xoaKhoangTrangThua(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (int j = i; j < len; j++) {
                s[j] = s[j + 1];
            }
            i--;
            len--;
        }
    }
    s[len] = '\0';
}

void vietHoaChuCaiDauTien(char s[]) {
    strlwr(s);
    s[0] = toupper(s[0]);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            s[i + 1] = toupper(s[i + 1]);
        }
    }
}

int demChuoiCon(char s[], char s2[]) {
    int dem = 0;
    char* p = s;
    while ((p = strstr(p, s2)) != NULL) {
        dem++;
        p++;
    }
    return dem;
}

int demKyTu(char s[], char kyTu) {
    int dem = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (tolower(s[i]) == tolower(kyTu)) {
            dem++;
        }
    }
    return dem;
}

int demTu(char s[]) {
    int demtu = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            demtu++;
        }
    }
    return demtu;
}

void noiChuoi(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    s1[len1] = ' ';
    for (int i = 0; i < len2; i++) {
        s1[len1 + 1 + i] = s2[i];
    }
    s1[len1 + 1 + len2] = '\0';
}

bool kiemTraDoiXung(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void inChuoiDaoNguoc(char s[]) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    char s1[50], s2[50], key;
    while (true) {
        system("cls");
        printf("************************************\n");
        printf("** THAO TAC TREN CHUOI **\n");
        printf("** 1. Nhap va chuan hoa chuoi **\n");
        printf("** 2. Dem so tu trong chuoi **\n");
        printf("** 3. Ghep chuoi **\n");
        printf("** 4. Kiem tra doi xung **\n");
        printf("** 5. In chuoi dao nguoc **\n");
        printf("** 0. Thoat **\n");
        printf("*************************************\n");
        fflush(stdin);
        printf("\n \t\t AN PHIM CHON: ");
        scanf("%c", &key);

        switch (key) {
        case '1':
            nhapChuoi(s1, "Nhap chuoi S1");
            nhapChuoi(s2, "Nhap chuoi S2");
            xoaKhoangTrangThua(s1);
            xoaKhoangTrangThua(s2);
            vietHoaChuCaiDauTien(s1);
            vietHoaChuCaiDauTien(s2);
            printf("\nChuoi sau khi chuan hoa:\nS1: %s\nS2: %s\n", s1, s2);
            break;
        case '2':
            if (strlen(s1) == 0) {
                printf("\nChua nhap chuoi S1. Vui long nhap chuoi truoc!");
            } else {
                int soTu = demTu(s1);
                printf("\nSo tu trong chuoi S1: %d\n", soTu);
            }
            break;
        case '3':
            if (strlen(s1) == 0) {
                printf("\nChua nhap chuoi S1. Vui long nhap chuoi truoc!");
            } else {
                nhapChuoi(s2, "Nhap chuoi S2 de ghep vao S1");
                noiChuoi(s1, s2);
                printf("\nSau khi ghep chuoi S2 vao S1:\nS1: %s\n", s1);
            }
            break;
        case '4':
            if (strlen(s1) == 0) {
                printf("\nChua nhap chuoi S1. Vui long nhap chuoi truoc!");
            } else {
                bool doiXung = kiemTraDoiXung(s1);
                if (doiXung) {
                    printf("\nChuoi S1 la chuoi doi xung.\n");
                } else {
                    printf("\nChuoi S1 khong phai chuoi doi xung.\n");
                }
            }
            break;
        case '5':
            if (strlen(s1) == 0) {
                printf("\nChua nhap chuoi S1. Vui long nhap chuoi truoc!");
            } else {
                printf("\nChuoi dao nguoc cua S1: ");
                inChuoiDaoNguoc(s1);
            }
            break;
        case '0':
            return 0;
        default:
            printf("\nKhong co chuc nang nay!");
            break;
        }

        printf("\nBam phim bat ky de tiep tuc!");
        getch();
    }

    return 0;
}

