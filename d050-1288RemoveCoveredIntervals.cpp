class Solution {
private:
    static bool srt(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), srt);
        int res = 0, right = 0;
        for (auto inter : intervals) {
            if (inter[1] > right) {
                res++;
                right = inter[1];
            }
        }
        return res;
    }
};