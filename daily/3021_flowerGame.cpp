class Solution {
public:
    long long flowerGame(int n, int m) {
        long long x = n;
        x *= m;
        x /= 2;
        return x;
    }
};