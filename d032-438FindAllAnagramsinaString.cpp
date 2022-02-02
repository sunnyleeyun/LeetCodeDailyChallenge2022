class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26), curr(26), res;
        for (char c : p) goal[c - 'a']++;
        for (int i = 0, n = s.size(); i < n; ++i) {
            curr[s[i] - 'a']++;
            if (i >= p.size()) curr[s[i - p.size()] - 'a']--;
            if (goal == curr) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};