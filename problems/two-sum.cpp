#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });
        int sum;
        int a = 0;
        int b = nums.size() - 1;
        while (a < b) {
            sum = nums[indices[a]] + nums[indices[b]];
            if (sum == target) {
                return {indices[a], indices[b]};
            } else if (sum < target) {
                a++;
            } else {
                b--;
            }
        }
        return {};
    }
};

void main() {
    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto res = solution.twoSum(nums, target);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
}