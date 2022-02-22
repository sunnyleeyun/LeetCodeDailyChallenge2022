class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, (n - i - 1));
        }
        return res;
    }
};