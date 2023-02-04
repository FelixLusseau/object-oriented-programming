#include <iostream>
using namespace std;

class Fraction {
  public:
    Fraction() {
        num = 0;
        den = 0;
    }
    Fraction(int num, int den) : num(num), den(den) {}

    Fraction additionne(Fraction const &frac) const {
        return Fraction(num * frac.den + frac.num * den, den * frac.den);
    }
    Fraction multiplie(Fraction const &frac) const {
        return Fraction(num * frac.num, den * frac.den);
    }
    void affiche() const { cout << num << "/" << den << endl; }
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

int main() {
    Fraction f1(4, 5);
    Fraction f2(8, 4);
    Fraction f3(f2);
    Fraction f4, f5;

    f4 = f3.multiplie(f2);
    f4.affiche();

    f3 = f1.additionne(f4);
    f1.affiche();

    cout << "PGCD(f4) = " << f4.pgcd() << endl;
    f5 = f4.simplifie();
    f5.affiche();
    return 0;
}