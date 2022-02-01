class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), M = 0;
        vector<int> arr(n);
        for (int i = n - 1; i >= 0; --i) {
            M = max(prices[i], M);
            arr[i] = M;
        }
        M = 0;
        for (int i = 0; i < n; ++i) {
            M = max(arr[i] - prices[i], M);
        }
        return M;
    }
};