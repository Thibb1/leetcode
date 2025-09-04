#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int, int> rmap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        int last = 0;
        for (auto &c: s) {
            res += rmap[c];
            res -= last < rmap[c] ? 2 * last : 0;
            last = rmap[c];
        }
        return res;
    }
};