class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int score = 0;
        for (auto &ch : s) {
            if (ch == '(') {
                stk.push(score);
                score = 0;
            } else {
                score = stk.top() + max(2 * score, 1);
                stk.pop();
            }
        }
        return score;
    }
};