class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int k = 0, n = nums.size();
        if (n == 0) return res;
        for (int i = 0; i <= n; ++i) {
            if (i == n || nums[k] != nums[i] - i + k) {
                if (k == i - 1) res.push_back(to_string(nums[k]));
                else res.push_back(to_string(nums[k]) + "->" + to_string(nums[i - 1]));
                k = i;
            }
        }
        return res;
    }
};