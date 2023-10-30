#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int x = abs(a), y = abs(b);
    while(x * y != 0) {
        if(x > y)
            x %= y;
        else
            y %= x;
    }

    return x + y;
}

class Fraction {
    private:
        int nume = 1, deno = 1;
    public:

        void input() {
        char _;
        cin >> nume >> _ >> deno;
        }
    
        void print() {
            cout << nume << "/" << deno << endl;
        } 
    
        Fraction* shorten() {
            int gcd = GCD(nume, deno);
            nume /= gcd;
            deno /= gcd;
            return this;
        }
        
        Fraction operator+(Fraction f) {
            Fraction tg;
            if(deno == f.deno) {
                tg.nume = nume + f.nume;
            } else {
                tg.nume = nume*f.deno + deno*f.nume;
                tg.deno = deno*f.deno;
            }
            return tg;
        }
        
        Fraction operator-(Fraction f) {
            Fraction tg;
            if(deno == f.deno) {
                tg.nume = nume - f.nume;
            } else {
                tg.nume = nume*f.deno - deno*f.nume;
                tg.deno = deno*f.deno;
            }
            return tg;
        }
        
        Fraction operator*(Fraction f) {
            Fraction tg;
            tg.nume = nume*f.nume;
            tg.deno = deno*f.deno;
            return tg;
        }
        
        Fraction operator/(Fraction f) {
            return f*reverse();
        }

        bool operator==(Fraction f) {
            return this->toDouble() == f.toDouble();
        }

        bool operator>(Fraction f){
            return this->toDouble() > f.toDouble();
        }

        bool operator>=(Fraction f){
            return *this > f || *this == f;
        }
        
        bool operator<(Fraction f){
            return this->toDouble() < f.toDouble();
        }

        bool operator<=(Fraction f){
            return *this < f || *this == f;
        }

        Fraction reverse() {
            Fraction tg;
            tg.deno = nume;
            tg.nume = deno;
            return tg;
        }

        double toDouble() {
            return (double)nume / (double)deno;
        }
};

int main() {
    int n;
    cout << "Input the number of fraction: ";
    cin >> n;

    Fraction* fractions = new Fraction[n];
    for(int i = 0; i < n; i++) {
        cout << "Input the fraction " << i + 1 << ": ";
        fractions[i].input();
    }
    
    cout << "Inputed fractions are: " << endl;
    for(int i = 0; i < n; i++) {
        fractions[i].print();
    }
    
    Fraction sum = fractions[0];
    for(int i = 1; i < n; i++){
        sum = sum + fractions[i];
    }
    cout << "Sum of fraction array is: ";
    sum.print();
    
    cout << "Shortened: ";
    sum.shorten()->print();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(fractions[i] < fractions[j]) {
                Fraction tg = fractions[i];
                fractions[i] = fractions[j];
                fractions[j] = tg;
            }
        }
    }
    cout << "Sorted fractions are: " << endl;
    for(int i = 0; i < n; i++) {
        fractions[i].print();
    }
}