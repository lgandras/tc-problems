#include<fraction.cpp>
#include<iostream>

using namespace std;

int main() {
  cout << Fraction<int>(10, 25) << endl;
  cout << Fraction<int>(10) << endl;
  cout << Fraction<int>(10) * Fraction<int>(2, 5) << endl;
  cout << Fraction<int>(10) / Fraction<int>(1, 2) << endl;
  cout << Fraction<int>(1, 2) - Fraction<int>(3, 4) << endl;
  return 0;
};
