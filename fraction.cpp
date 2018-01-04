#include<ostream>
#include<algorithm>

template <typename T>
class Fraction {
  void simplify() {
    T a = this->num, b = this->den;
    T ma = std::max(a, b), mi = std::min(a, b);
    while (mi < ma) {
      a = ma - mi;
      b = mi;
      ma = std::max(a, b);
      mi = std::min(a, b);
    }
    this->num /= ma;
    this->den /= ma;
  }
  public:
    T num, den;
    Fraction(T num, T den = 1) {
      this->num = num;
      this->den = den;
      this->simplify();
    }
};
template <typename T>
std::ostream& operator<<(std::ostream &strm, const Fraction<T> &f) {
  strm << f.num;
  if (1 < f.den) {
    strm << '/' << f.den;
  }
  return strm;
}

