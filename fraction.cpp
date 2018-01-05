#include<ostream>
#include<algorithm>

template <typename T>
class Fraction {
  void normalize() {
    this->num = this->num * (this->den < 0 ? -1 : 1);
    this->den = this->den * (this->den < 0 ? -1 : 1);
    T a = this->num * (this->num < 0 ? -1 : 1), b = this->den;
    T ma = std::max(a, b), mi = std::min(a, b);
    while (0 < mi) {
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
    Fraction(T num = 0, T den = 1) {
      this->num = num;
      this->den = den;
      this->normalize();
    }
    Fraction<T> operator*(const Fraction<T>& f) const {
      return Fraction<T>(this->num * f.num, this->den * f.den);
    }
    Fraction<T> operator-(const Fraction<T>& f) const {
      return Fraction<T>(this->num * f.den - f.num * this->den, this->den * f.den);
    }
    Fraction<T> operator/(const Fraction<T>& f) const {
      return Fraction<T>(this->num * f.den, this->den * f.num);
    }
    Fraction<T> operator+=(const Fraction<T>& f) {
      this->num = this->num * f.den + f.num * this->den;
      this->den = this->den * f.den;
      this->normalize();
    }
    Fraction<T> operator-=(const Fraction<T>& f) {
      this->num = this->num * f.den - f.num * this->den;
      this->den = this->den * f.den;
      this->normalize();
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

