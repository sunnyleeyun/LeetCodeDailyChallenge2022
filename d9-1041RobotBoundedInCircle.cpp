class Solution {
public:
    bool isRobotBounded(string instructions) {
        const int n = 4;
        bool hasG = false;
        int count = 0, x = 0, y = 0;
        for (char c : instructions) {
            if (c == 'G') { 
                hasG = true;
                int m = count < 0 ? (count % n + n) % n : count % n;
                if (m == 1) x++;
                else if (m == 2) y--;
                else if (m == 3) x--;
                else y++;
            } 
            else if (c == 'L') count--;
            else if (c == 'R') count++;
        }
        if ((count == 0 && hasG) || (count % 4 == 0 && !(x == 0 && y == 0))) return false;
        else return true;
    }
};