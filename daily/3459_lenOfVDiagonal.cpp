#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int gridLenX;
    int gridLenY;
    const int dx[4] = {-1,1,1,-1};
    const int dy[4] = {1,1,-1,-1};
public:
    bool isPointValid(vector<vector<int>>& grid, int x, int y, int targetValue) {
        return !(x >= gridLenX || y >= gridLenY || x < 0 || y < 0 || targetValue != grid[x][y]);
    }
    int lenDiag(vector<vector<int>>& grid, int dir, int x, int y, int target = 2, int canTurn = 1) {
        if (!isPointValid(grid, x, y, target)) return 0;
        int len = 1 + lenDiag(grid, dir, x + dx[dir], y + dy[dir], 2 - target, canTurn);
        if (canTurn) {
            int newDir = (dir + 1) % 4;
            len = max(len, 1 + lenDiag(grid, newDir, x + dx[newDir], y + dy[newDir], 2 - target, 0));
        }
        return len;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        gridLenX = grid.size();
        gridLenY = grid[0].size();
        int bestSize = 0;
        for (int x = 0; x < gridLenX; x++) {
            for (int y = 0; y < gridLenY; y++) {
                if (grid[x][y] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        int dirX = dx[dir] + x;
                        int dirY = dy[dir] + y;
                        bestSize = max(bestSize, 1 + lenDiag(grid, dir, dirX, dirY));
                    }
                }
            }
        }
        return bestSize;
    }
};

void main() {
    Solution solution;
    vector<vector<int>> grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    cout << "Running prog" << endl;
    auto res = solution.lenOfVDiagonal(grid);
    cout << res << endl;
}