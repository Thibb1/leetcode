#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double bestDiagSoFar = 0;
        int bestArea = 0;
        int h, w, area = 0;
        for (int idx = 0; idx < dimensions.size(); idx++) {
            h = dimensions[idx][0];
            w = dimensions[idx][1];
            area = h*w;
            if (sqrt(h*h+w*w) > bestDiagSoFar) {
                bestArea = area;
                bestDiagSoFar = sqrt(h*h+w*w);
            } else if (area > bestArea && sqrt(h*h+w*w) == bestDiagSoFar) {
                bestArea = area;
            }
        }
        return bestArea;
    }
};

void main() {
    Solution solution;
    vector<vector<int>> dimensions = {{9,3},{8,6}};
    auto res = solution.areaOfMaxDiagonal(dimensions);
    cout << res << endl;
}