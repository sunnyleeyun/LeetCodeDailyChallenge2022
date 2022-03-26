class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0, 1}};
        int sum = 0, cnt = 0;
        for (int &n : nums) {
            sum += n;
            if (m.count(sum - k)) cnt += m[sum - k];
            m[sum]++;
        }
        return cnt;
    }
};