class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0; 
        int mask = 0;
        
        for (int i = 31; i >= 0; --i) {
            mask = mask | (1 << i);
            set<int> s;
            for (int num : nums) {
                int leftPartOfNum = num & mask;
                s.insert(leftPartOfNum);
            }
                        
            int greedyTry = maxResult | (1 << i);
            for(int leftPartOfNum : s){
                if(s.count(leftPartOfNum ^ greedyTry)) {
                    maxResult = greedyTry;
                    break;
                }
            }
        }
        return maxResult;
    }
};