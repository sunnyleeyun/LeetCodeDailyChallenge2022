class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c1 = 0, c2 = n - 1, r1 = 0, r2 = n - 1, val = 1;
        vector<vector<int>> res(n, vector<int>(n));
        while (c1 <= c2 && r1 <= r2) {
            for (int i = c1; i <= c2; ++i)
                res[r1][i] = val++;
            r1++;
            for (int i = r1; i <= r2; ++i)
                res[i][c2] = val++;
            c2--;
            for (int i = c2; i >= c1; --i)
                res[r2][i] = val++;
            r2--;
            for (int i = r2; i >= r1; --i)
                res[i][c1] = val++;
            c1++;
        }
        return res;
    }
};