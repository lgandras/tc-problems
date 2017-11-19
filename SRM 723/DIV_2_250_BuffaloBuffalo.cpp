#include<string>

using namespace std;

class BuffaloBuffalo {
public:
  string check(string s);
};

string BuffaloBuffalo::check(string s) {
  int c = s.length();
  if (0 == c) {
    return "Good";
  }
  s += " ";
  for (int i = 0; i <= c; i += 8) {
    if (s.substr(i, 8) != "buffalo ") {
      return "Not good";
    }
  }
  return "Good";
};
