class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        
        vector<string> cur;
        dfs(0, s, cur, res);
        return res;
    }
    
    void dfs(int index, const string &s, vector<string> &cur, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = index; i < s.size(); ++i) {
            string sub = s.substr(index, i - index + 1);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                dfs(i + 1, s, cur, res);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) if (s[i++] != s[j--]) return false;
        return true;
    }
};