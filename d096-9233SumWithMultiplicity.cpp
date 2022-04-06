class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, long> m;
        for (auto &num : arr) {
            m[num]++;
        }
        long res = 0;
        for (auto it1 : m) {
            for (auto it2 : m) {
                int i = it1.first, j = it2.first, k = target - i - j;
                if (!m.count(k)) continue;
                if (i == j && j == k) 
                    res += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
                else if (i == j && j != k)
                    res += m[i] * (m[i] - 1) / 2 * m[k];
                else if (i < j && j < k)
                    res += m[i] * m[j] * m[k];
            }
        }
        return res % int(1e9 + 7);
    }
};