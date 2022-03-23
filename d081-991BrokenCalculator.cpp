class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while (target > startValue) {
            target = target % 2 == 1 ? (target + 1) : (target / 2);
            cnt++;
        }
        return cnt + startValue - target;
    }
};