class Solution {
private:
    // threshold can be split within m
    bool feasible(vector<int>& nums, int m, int threshold) {
        int count = 1;
        int total = 0;
        for (auto &num : nums) {
            total += num;
            if (total > threshold) {
                total = num;
                count++;
                if (count > m) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int l = -1, r = 0; // left -> max, right -> sum
        for (auto &num : nums) {
            l = max(l, num);
            r += num;
        }
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (feasible(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};