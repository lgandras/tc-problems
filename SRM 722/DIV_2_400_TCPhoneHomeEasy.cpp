#include<vector>
#include<cmath>
#include<string>

using namespace std;

class TCPhoneHomeEasy {
  public:
    int validNumbers(int digits, vector <string> specialPrefixes);
};

int TCPhoneHomeEasy::validNumbers(int digits, vector <string> specialPrefixes) {
  // all combinations after each prefix are substracted from the total
  int ret = pow(10, digits);
  for (vector<string>::iterator i = specialPrefixes.begin(); i != specialPrefixes.end(); ++ i) {
    int decimalPlaces = i->length();
    ret -= pow(10, digits - decimalPlaces);
  }
  return ret;
};
