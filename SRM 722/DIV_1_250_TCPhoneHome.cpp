#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class TCPhoneHome {
  public:
    long long validNumbers(int digits, vector <string> specialPrefixes);
};

long long TCPhoneHome::validNumbers(int digits, vector <string> specialPrefixes) {
  sort(specialPrefixes.begin(), specialPrefixes.end());
  long long ret = pow(10, digits);
  for (vector<string>::iterator i = specialPrefixes.begin(); i != specialPrefixes.end(); ++ i) {
    bool new_set = true;
    for (vector<string>::iterator j = specialPrefixes.begin(); j != i; ++ j) {
      if (i->substr(0, j->length()) == *j) {
        new_set = false;
        break;
      }
    }
    if (new_set) {
      long long k = 1;
      for (int m = 0; m < digits - i->length(); ++ m) {
        k *= 10;
      }
      ret -= k;
    }
  }
  return ret;
};
