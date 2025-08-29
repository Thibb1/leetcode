#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma GCC optimize ("O3")

class Solution {
public:
    int w;
    int h;
    int dim;
    int mid;
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        w = grid.size();
        h = grid[0].size();
        dim  = w + h - 1;
        vector<vector<int>> solve(dim);
        mid = dim / 2 + 0.5;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int idx = mid + x - y;
                solve[idx].push_back(grid[x][y]);
            }
        }
        for (int i = 0; i < dim; i++) {
            if (i < mid) {
                sort(solve[i].begin(), solve[i].end());
            } else {
                sort(solve[i].begin(), solve[i].end(), greater<int>());
            }
        }
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int idx = mid + x - y;
                grid[x][y] = solve[idx][0];
                solve[idx].erase(solve[idx].begin());
            }
        }
        return grid;
    }
};