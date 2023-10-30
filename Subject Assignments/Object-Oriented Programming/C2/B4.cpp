#include <bits/stdc++.h>

using namespace std;

char subjects[9][50] = {"Vat ly dai cuong", "Toan roi rac", "Lap trinh huong doi tuong", 
                        "CTDL&GT", "Co so du lieu", "Thiet ke web",
                        "Xu ly anh", "Tri tue nhan tao", "Quan ly du an CNTT"};

class Student {
    private:
        char name[50];
        int birthyear;
        float score[9];

        bool under5[9];
        bool hasUnder5;

    public:

        Student() {
            memset(score, 0, 9);
            memset(under5, 0, 9);
            hasUnder5 = false;
        }

        void input() {
            cout << "Input the student's full name: " << endl;
            cin.ignore(1);
            cin.get(name, 50);

            cout << "Input the student's birth year: ";
            cin >> birthyear;

            cout << "Input the student's scores:" << endl;
            for (int i = 0; i < 9; i ++) {
                cout << "\tSubject " << (i + 1) << ": ";
                cin >> score[i];

                if(score[i] < 5) {
                    hasUnder5 = true;
                    under5[i] = true;
                }
            }
        }

        float GPA() {
            float result = 0;
            for (int i = 0; i < 9; i++)
                result += score[i];
            return result / 9;
        }

        int printResult() {
            if(hasUnder5 == true) {
                cout << "Sinh vien " << name << " sinh nam " << birthyear << " phai thi lai mon: ";
                for (int i = 0; i < 9; i++)
                    if(under5[i]) {
                        cout << subjects[i] << ", ";
                    }
            } else {
                float gpa = GPA();
                if(gpa < 7) {
                    cout << "Sinh vien " << name << " sinh nam " << birthyear << " thi tot nghiep (GPA = " << gpa << ")";
                } else {
                    cout << "Sinh vien " << name << " sinh nam " << birthyear << " lam khoa luan (GPA = " << gpa << ")";
                }
            }
            cout << endl;
        }
};

int main() {
    cout << "Input the number of students: ";
    int n;
    cin >> n;

    Student students[n];

    for (int i = 1; i <= n; i++) {
        cout << "========= INPUT THE INFORMATION OF STUDENT " << i << " =========" << endl;
        students[i - 1].input();
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        students[i].printResult();
}