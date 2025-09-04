
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long total = 0;
        int sign = 0;
        int len = 0;
        bool number = false;
        for (auto &c: s) {
            if (len < 11 && c >= '0' && c <= '9') {
                total = 10 * (total + c - '0');
                len += total > 0;
                number = true;
            } else if (number || sign) {
                break;
            } else {
                sign = c == '-' ? 1 : c == '+' ? 2 : 0;
                if (!sign && c != ' ') break;
            }
        }
        if (sign == 1) total *= -1;
        total /= 10;
        return total > INT_MAX ? INT_MAX : total < INT_MIN ? INT_MIN : total;
    }
};