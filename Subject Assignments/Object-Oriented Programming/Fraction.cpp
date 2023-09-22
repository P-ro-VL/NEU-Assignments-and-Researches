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
        
        Fraction* add(Fraction* f) {
            if(deno == f->deno) {
                nume += f->nume;
            } else {
                nume = nume*f->deno + deno*f->nume;
                deno = deno*f->deno;
            }
            return this;
        }
        
        Fraction* subtract(Fraction* f) {
            if(deno == f->deno) {
                nume -= f->nume;
            } else {
                nume = nume*f->deno - deno*f->nume;
                deno = deno*f->deno;
            }
            return this;
        }
        
        Fraction* multiply(Fraction* f) {
            nume = nume*f->nume;
            deno = deno*f->deno;
            return this;
        }
        
        Fraction* devide(Fraction* f) {
            return multiply(f->reverse());
        }
        
        Fraction* reverse() {
            int temp = deno;
            deno = nume;
            nume = temp;
            return this;
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
        sum.add(&fractions[i]);
    }
    cout << "Sum of fraction array is: ";
    sum.print();
    
    cout << "Shortened: ";
    sum.shorten()->print();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(fractions[i].toDouble() < fractions[j].toDouble()) {
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