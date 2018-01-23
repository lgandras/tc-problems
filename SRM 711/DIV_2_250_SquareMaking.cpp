#include<cstdlib>
#include<algorithm>

using namespace std;

class SquareMaking {
  public:
    int getMinimalPrice(int a, int b, int c, int d) {
      return min(abs(b - a) + abs(c - a) + abs(d - a),
             min(abs(a - b) + abs(c - b) + abs(d - b),
             min(abs(a - c) + abs(b - c) + abs(d - c),
                 abs(a - d) + abs(b - d) + abs(c - d))));
    }
};
