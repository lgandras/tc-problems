#include<string>

using namespace std;

class OrAndSumEasy {
  public:
    string isPossible(long long pairOr, long long pairSum) {
      return ((pairSum - pairOr) & ~pairOr) == 0 ? "Possible" : "Impossible";
    };
};
