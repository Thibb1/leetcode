#include <algorithm>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1 = abs(x-z);
        int p2 = abs(y-z);
        return p1 == p2 ? 0 : p1 > p2 ? 2 : 1;
    }
};