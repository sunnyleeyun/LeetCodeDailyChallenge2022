class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int i = 1; i <= 9; ++i) q.push(i);
        vector<int> res;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (n >= low && n <= high) res.push_back(n);
            if (n > high) break;
            int r = n % 10;
            if (r < 9) q.push(n * 10 + r + 1);
        }
        return res;
    }
};