#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    printf("Moi ban chon bai tap (1-10): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int num1, num2;
            printf("Nhap vao hai so nguyen: ");
            scanf("%d %d", &num1, &num2);
            printf("Tong: %d\n", num1 + num2);
            printf("Hieu: %d\n", num1 - num2);
            printf("Tich: %d\n", num1 * num2);
            if (num2 != 0) {
                printf("Thuong: %.2f\n", (float)num1 / num2);
            } else {
                printf("Khong the chia cho 0.\n");
            }
            break;
        }
        case 2: {
            int number;
            printf("Nhap vao mot so co 3 chu so: ");
            scanf("%d", &number);
            int sum = 0;
            int product = 1;

            while (number > 0) {
                int digit = number % 10;
                sum += digit;
                product *= digit;
                number /= 10;
            }

            printf("Tong: %d\n", sum);
            printf("Tich: %d\n", product);
            break;
        }
        case 3: {
            int a, b;
            printf("Nhap vao hai so nguyen: ");
            scanf("%d %d", &a, &b);
            printf("So lon nhat: %d\n", (a > b) ? a : b);
            printf("So nho nhat: %d\n", (a < b) ? a : b);
            break;
        }
        case 4: {
            float toan, ly, hoa;
            printf("Nhap diem Toan, Ly, Hoa cua hoc sinh: ");
            scanf("%f %f %f", &toan, &ly, &hoa);
            float diemTB = (toan + ly + hoa) / 3;
            printf("Diem trung binh: %.2f\n", diemTB);

            if (diemTB >= 9.0) {
                printf("Xuat sac\n");
            } else if (diemTB >= 8.0) {
                printf("Gioi\n");
            } else if (diemTB >= 6.5) {
                printf("Kha\n");
            } else if (diemTB >= 5.0) {
                printf("Trung binh\n");
            } else if (diemTB >= 3.5) {
                printf("Yeu\n");
            } else {
                printf("Kem\n");
            }
            break;
        }
        case 5: {
            float a, b;
            printf("Nhap a va b: ");
            scanf("%f %f", &a, &b);
            if (a == 0) {
                if (b == 0) {
                    printf("Phuong trinh co vo so nghiem.\n");
                } else {
                    printf("Phuong trinh vo nghiem.\n");
                }
            } else {
                float x = -b / a;
                printf("Nghiem cua phuong trinh: x = %.2f\n", x);
            }
            break;
        }
        case 6: {
            int day;
            printf("Nhap vao so nguyen tu 1 den 7: ");
            scanf("%d", &day);
            switch (day) {
                case 1:
                    printf("Sunday\n");
                    break;
                case 2:
                    printf("Monday\n");
                    break;
                case 3:
                    printf("Tuesday\n");
                    break;
                case 4:
                    printf("Wednesday\n");
                    break;
                case 5:
                    printf("Thursday\n");
                    break;
                case 6:
                    printf("Friday\n");
                    break;
                case 7:
                    printf("Saturday\n");
                    break;
                default:
                    printf("So khong hop le.\n");
                    break;
            }
            break;
        }
        case 7: {
            float side1, side2, side3;
            printf("Nhap vao 3 so thuc a, b, c: ");
            scanf("%f %f %f", &side1, &side2, &side3);
            if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
                printf("Day la mot tam giac. ");
                if (side1 == side2 && side2 == side3) {
                    printf("Tam giac deu.\n");
                } else if (side1 == side2 || side1 == side3 || side2 == side3) {
                    if (side1 * side1 + side2 * side2 == side3 * side3 || side1 * side1 + side3 * side3 == side2 * side2 || side2 * side2 + side3 * side3 == side1 * side1) {
                        printf("Tam giac vuong can.\n");
                    } else {
                        printf("Tam giac can.\n");
                    }
                } else if (side1 * side1 + side2 * side2 == side3 * side3 || side1 * side1 + side3 * side3 == side2 * side2 || side2 * side2 + side3 * side3 == side1 * side1) {
                    printf("Tam giac vuong.\n");
                } else {
                    printf("Tam giac thuong.\n");
                }

                float p = (side1 + side2 + side3) / 2;
                float area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
                printf("Dien tich: %.2f\n", area);
                printf("Chieu dai cac duong cao: ha = %.2f, hb = %.2f, hc = %.2f\n", (2 * area / side1), (2 * area / side2), (2 * area / side3));
            } else {
                printf("Day khong phai la tam giac.\n");
            }
            break;
        }
        case 8: {
            float a, b, c;
            printf("Nhap a, b, va c: ");
            scanf("%f %f %f", &a, &b, &c);
            if (a == 0) {
                if (b == 0) {
                    if (c == 0) {
                        printf("Phuong trinh co vo so nghiem.\n");
                    } else {
                        printf("Phuong trinh vo nghiem.\n");
                    }
                } else {
                    float x = -c / b;
                    printf("Nghiem cua phuong trinh: x = %.2f\n", x);
                }
            } else {
                float discriminant = b * b - 4 * a * c;
                if (discriminant > 0) {
                    float x1 = (-b + sqrt(discriminant)) / (2 * a);
                    float x2 = (-b - sqrt(discriminant)) / (2 * a);
                    printf("Phuong trinh co 2 nghiem: x1 = %.2f, x2 = %.2f\n", x1, x2);
                } else if (discriminant == 0) {
                    float x = -b / (2 * a);
                    printf("Phuong trinh co nghiem kep: x = %.2f\n", x);
                } else {
                    printf("Phuong trinh vo nghiem.\n");
                }
            }
            break;
        }
        case 9: {
            char c;
            printf("Nhap mot chu cai: ");
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'z') {
                c = c - 32;
            } else if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            printf("Ket qua: %c\n", c);
            break;
        }
        case 10: {
            int kwh;
            printf("Nhap so Kwh tieu thu: ");
            scanf("%d", &kwh);
            float totalCost = 0;
            if (kwh <= 100) {
                totalCost = kwh * 455.0;
            } else if (kwh <= 150) {
                totalCost = 100 * 455.0 + (kwh - 100) * 591.0;
            } else if (kwh <= 200) {
                totalCost = 100 * 455.0 + 50 * 591.0 + (kwh - 150) * 818.0;
            } else {
                totalCost = 100 * 455.0 + 50 * 591.0 + 50 * 818.0 + (kwh - 200) * 1000.0;
            }
            printf("Tien dien phai tra: %.2f VND\n", totalCost);
            break;
        }
        default:
            printf("Lua chon khong hop le.\n");
    }

    return 0;
}
