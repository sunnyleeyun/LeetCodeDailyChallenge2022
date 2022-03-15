class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0, n = s.length(); i < n; ++i) {
            switch (s[i]) {
                case '(': stk.push(i); break;
                case ')':
                    if (stk.empty()) s[i] = '*';
                    else stk.pop();
                    break;
                default: break;
            }
        }
        
        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};