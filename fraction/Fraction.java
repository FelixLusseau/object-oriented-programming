public class Fraction {
    // main
    static public void main(String args[]) {
        Fraction f1 = new Fraction(1, 2);
        Fraction f2 = new Fraction(3, 5);

        Fraction f3;
        f3 = f1.additionne(f2);
        f3.affiche();

        Fraction f4;
        f4 = f1.multiplie(f3);
        f4.affiche();
    }

    private int num;
    private int den;

    public Fraction(int num, int den) {
        this.num = num;
        this.den = den;
    }

    public Fraction additionne(Fraction frac) {
        Fraction res = new Fraction(num * frac.den + frac.num * den, den * frac.den);
        return res;
    }

    public Fraction multiplie(Fraction frac) {
        Fraction res = new Fraction(num * frac.num, den * frac.den);
        return res;
    }

    public void affiche() {
        System.out.println(num + "/" + den);
        // System.out.print(num + "/" + den + "\n");
    }

    int _pgcd(int a, int b) {
        int r = a % b;
        if (r == 0)
            return b;
        else
            return _pgcd(b, r);
    }

    public int pgcd() {
        return _pgcd(num, den);
    }
}
