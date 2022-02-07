class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        for (char c : t) {
            m[c]--;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == -1) return it->first;
        }
        return t[0];
    }
};