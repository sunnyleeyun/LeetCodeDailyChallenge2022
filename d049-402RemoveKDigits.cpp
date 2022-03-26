class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (auto ch : num) {
            while (res.length() && res.back() > ch && k) {
                res.pop_back();
                k--;
            }
            if (res.length() || ch != '0') res.push_back(ch);
        }
        
        while (res.length() && k--) res.pop_back();
        
        return res.empty() ? "0" : res;
    }
};