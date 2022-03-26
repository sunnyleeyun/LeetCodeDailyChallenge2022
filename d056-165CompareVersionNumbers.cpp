class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        int i1 = 0, i2 = 0;
        while (i1 < n1 || i2 < n2) {
            string j1 = "", j2 = "";
            if (i1 >= n1) j1 = "0";
            else {
                for (int i = i1; i < n1; ++i) {
                    i1 = i + 1; 
                    if (version1[i] == '.') break;
                    j1.push_back(version1[i]);
                }
            }
            if (i2 >= n2) j2 = "0";
            else {
                for (int i = i2; i < n2; ++i) {
                    i2 = i + 1;
                    if (version2[i] == '.') break;
                    j2.push_back(version2[i]);
                }
            }
            
            if (stoi(j1) > stoi(j2)) return 1;
            else if (stoi(j1) < stoi(j2)) return -1;
        }
        
        return 0;
    }
};