#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int bsf = 0;
        int start = 0;
        int end = 1;
        for (; end <= s.size(); end++) {
            string sub = s.substr(start, end - start);
            int pos = sub.find(s[end]);
            int len = sub.size();
            bsf = max(bsf, len);
            if (pos != string::npos) {
                start += 1 + pos;
            }
        }
        return bsf;
    }
};