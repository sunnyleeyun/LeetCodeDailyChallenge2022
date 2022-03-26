class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> V(26), res;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            V[s[i] - 'a'] = i;
        }
        
        int maxIdx = -1, lastIdx = 0;
        for (int i = 0; i < n; ++i) {
            maxIdx = max(maxIdx, V[s[i] - 'a']);
            if (maxIdx == i) {
                res.push_back(i - lastIdx + 1);
                lastIdx = i + 1;
            }
        }
        return res;
    }
};