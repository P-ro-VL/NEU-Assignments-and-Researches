#include <bits/stdc++.h>

using namespace std;

class Time {
    private:
        int h, m, s;
    public:
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    int getHour() { return h; }
    int getMinute() { return m; }
    int getSecond() { return s; }

    Time normalize() {
        m += s / 60;
        s = s % 60;
        h += m / 60;
        m = m % 60;
        h = h % 24;

        return *this;
    }

    void advance(int h, int m, int s) {
        this->h += h;
        this->m += m;
        this->s += s;
    }

    void reset(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    void print() {
        cout << h << ":" << m << ":" << s;
    }
};

int main() {
    Time time(3, 15, 0);
    time.advance(0, 80, 0);
    time.normalize().print();
}