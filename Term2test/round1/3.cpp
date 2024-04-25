#include <iostream>
#include <string>
using namespace std;

class Complex {
  public:
    Complex(double r, double i) : Real(r), Image(i) {}
    Complex() {}
    bool operator==(Complex other) {
        return Real == other.Real && Image == other.Image;
    }
    bool operator!=(Complex other) { return !(*this == other); }
    Complex operator-() {
        Complex res(-Real, -Image);
        return res;
    }
    friend ostream &operator>>(ostream &output, const Complex &);

  private:
    double Real, Image;
};
ostream &operator>>(ostream &output, const Complex &in) {
    output << "(" << in.Real << " + " << in.Image << "i)";
    return output;
}

int main() {
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout >> c << endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
}