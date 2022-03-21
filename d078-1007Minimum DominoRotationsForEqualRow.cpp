class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> T(7), B(7), S(7); // Top, Bottom, Same
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            T[tops[i]]++;
            B[bottoms[i]]++;
            if (tops[i] == bottoms[i])
                S[tops[i]]++;
        }
        for (int i = 1; i < 7; ++i) {
            if ((T[i] + B[i] - S[i]) == n)
                return n - max(T[i], B[i]);
        }
        return -1;
    }
};