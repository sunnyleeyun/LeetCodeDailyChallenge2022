class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        while (k > 0) {
            res[--n] += min(k, 25);
            k -= min(k, 25);
        }
        return res;
    }
};