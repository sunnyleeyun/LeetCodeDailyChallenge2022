class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res = 0;
        map<int, int> m;
        for (int &n1 : nums1) {
            for (int &n2 : nums2) m[n1 + n2]++;
        }
        for (int &n3 : nums3) {
            for (int &n4 : nums4) {
                if (m[-n3 - n4] > 0) res += m[-n3 - n4];
            }
        }
        return res;
    }
};