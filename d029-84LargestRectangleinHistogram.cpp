class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> l(n), r(n);
        l[0] = -1;
        r[n - 1] = n;
        for (int i = 1; i < n; ++i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) p = l[p];
            l[i] = p;
        }
        
        for (int i = n - 2; i >= 0; --i) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) p = r[p];
            r[i] = p;
        }
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, heights[i] * (r[i] - l[i] - 1));
        }
        return maxArea;
                                     
    }
};