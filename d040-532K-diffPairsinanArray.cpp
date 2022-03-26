class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        int res = 0;
        for (int &n : nums) {
            m[n]++;
        }
        for (auto &item : m) {
            if (k == 0) {
                if (item.second >= 2) res++;
            } else {
                if (m.count(item.first + k)) res++;
            }
        }
        return res;
    }
};