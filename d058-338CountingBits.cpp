class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int k = i, t = 0;
            while (k) {
                t += k % 2 == 1 ? 1 : 0;
                k /= 2;
            }
            res.push_back(t);
        }
        return res;
    }
};