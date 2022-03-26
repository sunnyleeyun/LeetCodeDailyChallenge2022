class Solution {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            int t = 0;
            while (num) {
                t += num % 10;
                num /= 10;
            }
            num = t;
        }
        return num;
    }
};