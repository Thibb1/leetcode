#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int len = nums.size();
        int bsf = abs(nums[0]-nums[len-1]);
        for (int i = 0; i < len-1; i++) {
            bsf = max(bsf, abs(nums[i]-nums[i+1]));
        }
        return bsf;
    }
};