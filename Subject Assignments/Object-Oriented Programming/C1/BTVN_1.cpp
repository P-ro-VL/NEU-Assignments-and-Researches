#include <bits/stdc++.h>
#include <conio.h>
#include <iomanip>

using namespace std;

struct SV {
    char maSV[10];
    char hoTen[100];
    double GPA;
};

int main() {
    int n;
    scanf("%d", &n);

    SV* students = new SV[n];

    if (students == NULL) {
        cout << "\n Loi cap phat vung nho";
        getch();
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        cin.ignore(1);
        cin.get(students[i].maSV, 10);
        cin.ignore(1);
        cin.get(students[i].hoTen, 100);
        cin >> students[i].GPA;
    }

    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(students[i].GPA > students[j].GPA) {
                SV tg = students[i];
                students[i] = students[j];
                students[j] = tg;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        SV sv = students[i];
        cout << sv.maSV << " " << sv.hoTen << " " << sv.GPA << endl;
    }

    delete students;
}