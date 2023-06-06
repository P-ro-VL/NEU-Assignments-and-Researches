#include <stdio.h>

typedef struct
{
    char maLop[6];
    char tenGiangVien[17];

    float heSo;

    int soTietGiang;

    long donGia;
    long soTienGiang;
} GiangDay;

long TienGiang(int soTiet, float heSo, long donGia);
void printList(GiangDay *instances, int size);
void sortByTotalWage();

int nextIndex = 0;
GiangDay instances[10000];

int main() {
    printf(">> Nhap so mon: ");
    int n;
    scanf("%d", &n);

    while(n--) {
        GiangDay giangDay;

        printf(">> Nhap du lieu mon giang day %d", (nextIndex + 1));
        fflush(stdin);
        printf("\n\tMa lop: ");
        gets(giangDay.maLop);

        fflush(stdin);
        printf("\tTen giang vien: ");
        gets(giangDay.tenGiangVien);

        printf("\tSo tiet: ");
        scanf("%d", &giangDay.soTietGiang);

        printf("\tHe so: ");
        scanf("%f", &giangDay.heSo);

        printf("\tDon gia: ");
        scanf("%ld", &giangDay.donGia);

        giangDay.soTienGiang = TienGiang(giangDay.soTietGiang, giangDay.heSo, giangDay.donGia);

        instances[nextIndex] = giangDay;
        nextIndex++;
    }

    printf("\n");
    printList(instances, nextIndex);
    printf(">> Sorted list by total wage: \n");
    sortByTotalWage();
}

long TienGiang(int soTiet, float heSo, long donGia) {
    return soTiet * heSo * donGia;
}

void printList(GiangDay *instaces, int size) {
    printf("|---|-----|----------------|-------|-----|--------|----------|\n");
    printf("|STT|MALOP| TEN GIANG VIEN |SO TIET|HE SO|DON GIA | SO TIEN  |\n");
    printf("|---|-----|----------------|-------|-----|--------|----------|\n");

    for (int i = 0; i < size; i++) {
        GiangDay giangDay = instances[i];
        printf("| %-2d|%-5s|%-16s|%-7d|%-5.2f|%-8d|%-10ld|\n", 
        (i+1),
        giangDay.maLop,
        giangDay.tenGiangVien,
        giangDay.soTietGiang,
        giangDay.heSo,
        giangDay.donGia,
        giangDay.soTienGiang);
    }

    printf("|---|-----|----------------|-------|-----|--------|----------|\n");
}

void sortByTotalWage() {
    for (int i = 0; i < nextIndex; i++) {
        for (int j = 0; j < nextIndex; j++) {
            if(instances[i].soTienGiang > instances[j].soTienGiang) {
                GiangDay temp = instances[i];
                instances[i] = instances[j];
                instances[j] = temp;
            }
        }
    }

    printList(instances, nextIndex);
}