class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, start = 0, n = seats.size();
        for (int i = 1; i < n; ++i) {
            if (i == n - 1 && seats[i] == 0) {
                res = max(res, i - start);
            } else if (seats[i] == 1) {
                if (start == 0 && seats[0] == 0) {
                    res = max(res, i);
                    start = i;
                } else {
                    int d = i - start;
                    int mid = d / 2 + start;
                    res = max(res, mid - start);
                    start = i;
                }
            }
        }
        return res;
    }
};