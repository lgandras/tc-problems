#include<lagrange_interpolation.cpp>
#include<vector>
#include<fraction.cpp>
#include<iostream>
#include<utility>

using namespace std;

int main() {
  //vector<pair<int, int> > v;
  //v.push_back(make_pair(1, 0));
  //v.push_back(make_pair(2, 1));
  //vector<int> c = lagrange_interpolation(v);
  vector<pair<Fraction<int>, Fraction<int> > > v;
  //v.push_back(make_pair(Fraction<int>(-1), Fraction<int>(2)));
  //v.push_back(make_pair(Fraction<int>(0), Fraction<int>(0)));
  //v.push_back(make_pair(Fraction<int>(1), Fraction<int>(2)));
  v.push_back(make_pair(Fraction<int>(0), Fraction<int>(0)));
  v.push_back(make_pair(Fraction<int>(1), Fraction<int>(16)));
  v.push_back(make_pair(Fraction<int>(2), Fraction<int>(600)));
  v.push_back(make_pair(Fraction<int>(3), Fraction<int>(4680)));
  v.push_back(make_pair(Fraction<int>(4), Fraction<int>(19904)));
  v.push_back(make_pair(Fraction<int>(5), Fraction<int>(61000)));
  vector<Fraction<int> > c = lagrange_interpolation(v);
  for (int i = 0; i < c.size(); ++ i) {
    cout << "c[" << i << "] = " << c[i] << endl;
  }
  return 0;
}
