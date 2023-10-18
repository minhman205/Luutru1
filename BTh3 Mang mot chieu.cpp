#include <stdio.h>


int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }

    return 1;
}

int main() {
    int n;
    printf("1. Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("2. Nhap mang %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("   a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("3. Mang vua nhap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("4. Gia tri lon nhat trong mang: %d\n", max);

    
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    printf("5. Tich cac phan tu trong mang: %d\n", product);

    
    int countPrimes = 0;
    int sumPrimes = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            countPrimes++;
            sumPrimes += arr[i];
        }
    }
    printf("6. So phan tu nguyen to trong mang: %d\n", countPrimes);
    printf("   Tong cua cac phan tu nguyen to: %d\n", sumPrimes);

    
    int x;
    printf("7. Nhap gia tri x: ");
    scanf("%d", &x);
    int found = 0;
    printf("   Vi tri cac phan tu co gia tri %d: ", x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri %d trong mang.", x);
    }
    printf("\n");

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("8. Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    int insertIndex;
    printf("9. Nhap gia tri can chen (x): ");
    scanf("%d", &x);
    printf("   Nhap vi tri can chen (0 <= vi tri < %d): ", n);
    scanf("%d", &insertIndex);

    if (insertIndex < 0 || insertIndex > n) {
        printf("Vi tri chen khong hop le.\n");
    } else {
        for (int i = n - 1; i >= insertIndex; i--) {
            arr[i + 1] = arr[i];
        }
        arr[insertIndex] = x;
        n++; 
        printf("   Mang sau khi chen gia tri %d: ", x);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    
    int k;
    printf("10. Nhap gia tri can xoa (k): ");
    scanf("%d", &k);
    int numDeleted = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--; 
            numDeleted++;
            i--; 
        }
    }
    if (numDeleted > 0) {
        printf("   Mang sau khi xoa gia tri %d: ", k);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Khong tim thay gia tri %d de xoa trong mang.", k);
    }
    printf("\n");

    return 0;
}

