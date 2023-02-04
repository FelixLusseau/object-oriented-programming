#include <iostream>
using namespace std;

class Fraction {
  public:
    Fraction() {
        num = 0;
        den = 0;
    }
    Fraction(int num, int den) : num(num), den(den) {}

    Fraction operator+(Fraction &frac) const {
        return Fraction(num * frac.den + frac.num * den, den * frac.den);
    }
    Fraction operator*(Fraction &frac) const {
        return Fraction(num * frac.num, den * frac.den);
    }
    int get_num() const { return num; }
    int get_den() const { return den; }
    int pgcd() const { return _pgcd(num, den); }
    Fraction simplifie() {
        int valpgcd = this->pgcd();
        return Fraction(num / valpgcd, den / valpgcd);
    }

  private:
    int num;
    int den;
    int _pgcd(int a, int b) const {
        int r = a % b;

        if (r == 0)
            return b;
        else
            return _pgcd(b, r);
    }
};

ostream &operator<<(ostream &sortie, Fraction const &frac) {
    sortie << frac.get_num() << "/" << frac.get_den() << endl;
    return sortie;
}

int main() {
    Fraction f1(4, 5);
    Fraction f2(8, 4);
    Fraction f3(f2);
    Fraction f4, f5;

    f4 = f3 * f2;
    cout << f4;

    f3 = f1 + f4;
    cout << f1;

    cout << "PGCD(f4) = " << f4.pgcd() << endl;
    f5 = f4.simplifie();
    cout << f5;
    return 0;
}