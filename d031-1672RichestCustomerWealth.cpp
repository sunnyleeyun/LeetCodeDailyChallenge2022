class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        int n = accounts.size();
        for (int i = 0; i < n; ++i) {
            int total = 0;
            for (int acc : accounts[i]) total += acc;
             res = max(res, total);
        }
        return res;
    }
};