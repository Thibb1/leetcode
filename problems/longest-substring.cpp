#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int bsf = 0;
        int left = 0;
        int right = 0;
        vector<int> chars(256);
        fill(chars.begin(), chars.end(), -1);
        for (; right < s.size(); right++) {
            int pos = chars[s[right]];
            chars[s[right]] = right;
            if (pos != -1 && pos >= left) {
                left = 1 + pos;
            } else {
                bsf = max(bsf, right - left + 1);
            }
        }
        return bsf;
    }
};