class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        if (s.empty() && t.empty()) return true;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) { i++; j++; }
            else j++;
            if (i == s.length()) return true;
        }
        
        return i == s.length() && j < t.length();
    }
};