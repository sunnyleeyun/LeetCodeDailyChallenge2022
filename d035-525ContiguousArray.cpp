class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (m.count(sum)) maxLen = max(maxLen, i - m[sum]);
            else m[sum] = i;
        }
        return maxLen;
    }
};