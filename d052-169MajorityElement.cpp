class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums.size() / 2;
        unordered_map<int, int> m;
        for (auto n : nums) {
            if (++m[n] > k) return n;
        }
        return 0;
    }
};