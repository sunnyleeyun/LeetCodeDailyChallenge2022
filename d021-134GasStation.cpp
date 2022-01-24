class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, tank = 0, index = 0;
        for (int i = 0; i < n; ++i) {
            int cur = gas[i] - cost[i];
            total += cur;
            tank += cur;
            if (tank < 0) {
                tank = 0;
                index = i + 1;
            }
        }
        return total < 0 ? -1 : index;
    }
};