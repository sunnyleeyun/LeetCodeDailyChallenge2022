class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int ele = matrix[mid / n][mid % n];
            if (ele == target) return true;
            if (ele > target) r = mid;
            else l = mid + 1;
        }
        return false;
    }
};