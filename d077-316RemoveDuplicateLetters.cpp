class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> V(26);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            V[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26);
        stack<char> stk;
        
        for (int i = 0; i < n; ++i) {
            if (seen[s[i] - 'a']) continue;
            while (!stk.empty() && stk.top() > s[i] && i < V[stk.top() - 'a']) {
                seen[stk.top() - 'a'] = false;
                stk.pop();
            }
            seen[s[i] - 'a'] = true;
            stk.push(s[i]);
        }
        
        string res = "";
        while (!stk.empty()) {
            res += stk.top(); stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};