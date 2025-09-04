#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int revert = 0;
        while (x != 0) {
            int nb = x % 10;
            if (revert > INT_MAX / 10 || (revert == INT_MAX / 10 && nb > 7)) return 0;
            if (revert < INT_MIN / 10 || (revert == INT_MIN / 10 && nb < -8)) return 0;
            revert = revert * 10 + nb;
            x /= 10;
        }
        return revert;
    }
};