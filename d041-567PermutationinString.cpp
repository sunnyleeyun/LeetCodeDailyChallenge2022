class Solution {
private:
    bool allZeros( vector<int> &vec) {
        for (int v : vec) if (v != 0) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<int> vec(26, 0);
        for (auto s : s1) {
            vec[s - 'a']++;
        }
        for (int i = 0; i < n2; ++i) {
            char s = s2[i];
            vec[s - 'a']--;
            if (i - n1 >= 0) vec[s2[i - n1] - 'a']++;
            if (allZeros(vec)) return true;
        }
        return false;
    }
};