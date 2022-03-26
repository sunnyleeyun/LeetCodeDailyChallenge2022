class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), 
             [](const vector<int> &A, const vector<int> &B) {
                return A[0] - A[1] < B[0] - B[1];
             });
        int n = costs.size() / 2, res = 0;
        for (int i = 0; i < n; ++i) {
            res += costs[i][0] + costs[n + i][1];
        }
        return res;
    }
};