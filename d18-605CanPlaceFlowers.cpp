class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if (m == 1) {
            if ((flowerbed[0] == 1 && n == 0) || (flowerbed[0] == 0 && n <= 1)) return true;
            else return false;
        }
        int maxN = 0;
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 1) continue;
            if (i == 0) {
                if (flowerbed[i + 1] == 0) flowerbed[i] = 1, maxN++;
            } else if (i == m - 1) {
                if (flowerbed[i - 1] == 0) flowerbed[i] = 1, maxN++;
            } else {
                int prev = flowerbed[i - 1], next = flowerbed[i + 1];
                if (prev == 0 && next == 0) flowerbed[i] = 1, maxN++;
            }
        }
        return maxN >= n;
    }
};