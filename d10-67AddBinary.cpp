class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        string res = "";
        int rem = 0;
        while (i >= 0 || j >= 0 || rem != 0) {
            int m = i >= 0 ? a[i] - '0' : 0;
            int n = j >= 0 ? b[j] - '0' : 0;
            int t = m + n + rem;
            res += to_string(t % 2);
            rem = (t / 2);
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};