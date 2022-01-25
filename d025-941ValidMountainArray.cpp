class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        bool isClimbing = true;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) return false;
            if (isClimbing && arr[i] < arr[i - 1]) {
                if (i == 1) return false;
                else isClimbing = false;
            } else if (!isClimbing && arr[i] > arr[i - 1]) return false;
        }
        return !isClimbing && true;
    }
};