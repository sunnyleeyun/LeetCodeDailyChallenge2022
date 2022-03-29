class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> m;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            int total = 0;
            for (auto &mt : mat[i]) {
                total += mt;
            }
            m[total].push_back(i);
        }
        vector<int> res;
        for (auto &e : m) {
            if (k >= e.second.size()) {
                res.insert(res.end(), e.second.begin(), e.second.end());
                k -= e.second.size();
            } else {
                for (int i = 0, n = k; i < n; ++i) {
                    res.push_back(e.second[i]);
                }
                k = 0;
            }
            if (k == 0) break;
        }
        return res;
    }
};