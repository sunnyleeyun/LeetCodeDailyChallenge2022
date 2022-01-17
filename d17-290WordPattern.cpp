class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int j = 0, n = s.size();
        unordered_map<string, string> d;
        for (char pat : pattern) {
            string p = to_string(pat);
            string temp = "";
            while (j < n) {
                if (s[j] == ' ') {
                    j++;
                    break;
                } else temp += s[j++];
            }
            if (temp == "") return false;
            if (d.count(temp) == 0 && d.count(p) == 0) {
                d[temp] = p;
                d[p] = temp;
            } else {
                if (d[temp] != p || d[p] != temp) return false;
            }
        }
        if (j < n) return false;
        return true;
    }
};