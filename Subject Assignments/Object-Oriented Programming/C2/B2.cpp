#include <bits/stdc++.h>

using namespace std;

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int min(int a, int b) {
    return a > b ? b : a;
}

class Date {
    private:
        int d, m, y;
    public:
        Date(){}
        Date(int d, int m, int y) {
            this->d = d;
            this->m = m;
            this->y = y;
        }

        void input() {
            cout << "Nhap dd/MM/yyyy: ";
            char _, __;
            cin >> d >> _ >> m >> __ >> y;
        }

        void print() {
            cout << d << "/"
                 << m
                 << "/" << y << endl;
        }

        int daysIn(int m) {
            int day = daysInMonth[m - 1];
            if(m == 2 && (y % 4 == 0 && y % 100 != 0)) {
                day = 29;
            }
            return day;
        }

        Date normalize() {
            y += m / 12;
            m %= 12;

            while(d > daysIn(m)) {
                d -= daysIn(m);
                m += 1;
                if(m > 12) {
                    m = 1;
                    y++;
                }
            }
            return *this;
        }

        void reset(int d, int m, int y) {
            this->d = d;
            this->m = m;
            this->y = y;
        }
        
        void advance(int d, int m, int y) {
            this->y += y;
            this->m += m;
            this->d += d;
        }

        int operator-(Date date) {
            int count = 0;
            Date tg;
            tg.d = date.d;
            tg.m = date.m;
            tg.y = date.y;
            while(tg != *this) {
                tg.advance(1, 0, 0);
                tg.normalize();
                count++;
            } 
            return count;
        }

        bool operator==(Date time){
            return d == time.d && m == time.m && y == time.y;
        }

        bool operator!=(Date time) {
            return (*this == time) == 0;
        }

};

int main() {
    Date date(28, 2, 2023);
    cout << "Current Date: ";
    date.normalize().print();
    date.advance(125, 37, 10);
    date.print();
    cout << "Date after adding 31 days and 1 month: ";
    date.normalize().print();
    Date date2(28, 9, 3000);
    int count = date2 - date;
    cout << "The number of day between 28/09/2023 and current date is: " << count ;
}