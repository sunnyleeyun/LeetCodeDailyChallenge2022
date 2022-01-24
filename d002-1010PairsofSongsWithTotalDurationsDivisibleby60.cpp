class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int res = 0;
        vector<int> count(60, 0);
        for (int i = 0; i < n; ++i) {
            int r = time[i] % 60;
            int d = 60 - r;
            if (d == 60) d = 0;
            res += count[d];
            count[r]++;
        }
        return res;
    }
};