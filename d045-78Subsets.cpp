class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
        for (int i = index; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            backtrack(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(nums, 0, tmp, res);
        return res;
    }
};