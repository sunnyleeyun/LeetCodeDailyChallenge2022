class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        sort(points.begin(), points.end(), cmp);
        int arrPos = points[0][1];
        int arrCnt = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (arrPos >= points[i][0]) continue;
            arrPos = points[i][1];
            arrCnt++;
        }
        return arrCnt;
    }
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
};