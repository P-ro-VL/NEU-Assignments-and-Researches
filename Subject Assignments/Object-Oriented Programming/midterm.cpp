#include <bits/stdc++.h>

using namespace std;

class MOITRUONG {
    private:
        char maDoiTuong[9];
        char tenDoiTuong[20];
        int CSMT;
    public:
        MOITRUONG() {
            CSMT = 0;
        }

        void nhap() {
            cout << "Nhap ma doi tuong: ";
            cin.ignore(1);
            cin.get(maDoiTuong, 9);

            cout << "Nhap ten doi tuong: ";
            cin.ignore(1);
            cin.get(tenDoiTuong, 20);

            while(!(CSMT >= 20 && CSMT <= 80)) {
                cout << "Nhap CSMT (trong khoang 20 - 80): ";
                cin.ignore(1);
                cin >> CSMT;
            }
        }

        void in() {
            printf("| %-13s| %-19s| %-5d|\n", maDoiTuong, tenDoiTuong, CSMT);
        }

        int getCSMT() {
            return CSMT;
        }

        bool operator>(MOITRUONG t2) {
            return CSMT > t2.CSMT ? true : false;
        }
};

void printHeader();
void printFooter();

int main() {
    cout << "Nhap so luong doi tuong: ";
    int n;
    cin >> n;

    MOITRUONG arr[n];

    for (int i = 0; i < n; i++) {
        cout << "====== NHAP THONG TIN CHO DOI TUONG THU " << i+1 << " ======" << endl;
        arr[i].nhap();
    }

    cout << endl << "Cac doi tuong vua nhap la:" << endl;
    printHeader();
    for (int i = 0; i < n; i++) {
        arr[i].in();
    }
    printFooter();

    int maxCSMT = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i].getCSMT() > maxCSMT) {
            maxCSMT = arr[i].getCSMT();
        }
    }

    cout << endl << "Cac doi tuong co CSMT lon nhat la:" << endl;
    printHeader();
    for (int i = 0; i < n; i++) {
        if(arr[i].getCSMT() == maxCSMT) {
            arr[i].in();
        }
    }
    printFooter();

    int sumCSMT = 0;
    for (int i = 0; i < n; i++) {
        sumCSMT += arr[i].getCSMT();
    }
    cout << endl
            << "Tong so doi tuong: " << n << " | Tong so CSMT cua tat ca doi tuong: " << sumCSMT;
}

void printHeader() {
    cout << "|--------------|--------------------|------|" << endl;
    cout << "| MA DOI TUONG | TEN DOI TUONG      | CSMT |" << endl;
    cout << "|--------------|--------------------|------|" << endl;
}

void printFooter() {
    cout << "|--------------|--------------------|------|" << endl;
}