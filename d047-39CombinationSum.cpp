class Solution {
private:
    void backtrack(vector<int>& candidates, int start, int remain, vector<int>& tmp, vector<vector<int>>& res) {
        if (remain < 0) return;
        if (remain == 0) res.push_back(tmp);
        else {
            for (int i = start; i < candidates.size(); ++i) {
                tmp.push_back(candidates[i]);
                backtrack(candidates, i, remain - candidates[i], tmp, res);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(candidates, 0, target, tmp, res);
        return res;
    }
};