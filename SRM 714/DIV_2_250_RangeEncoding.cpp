#include<vector>

using namespace std;

class RangeEncoding {
  public:
    int minRanges(vector <int> arr) {
      int ret = 1;
      for (int i = 1; i < arr.size(); ++ i) {
        if (arr[i - 1] + 1 < arr[i]) {
          ++ ret;
        }
      }
      return ret;
    }
};
