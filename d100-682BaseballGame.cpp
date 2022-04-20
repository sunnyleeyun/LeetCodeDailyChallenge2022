class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (auto op : ops) {
            if (isdigit(op[0]) || op[0] == '-') {
                stk.push(stoi(op));
                continue;
            }
            switch (op[0]) {
                case 'C': {
                    stk.pop();
                    break;
                }
                case 'D': {
                    stk.push(stk.top() * 2);
                    break;
                }
                default: {
                    int x = stk.top(); stk.pop();
                    int y = stk.top(); stk.pop();
                    stk.push(y);
                    stk.push(x);
                    stk.push(x + y);
                }
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};