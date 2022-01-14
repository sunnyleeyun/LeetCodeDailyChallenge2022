class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
		
        while(i < n) {
            if(s[i] == ' ') i++;
            else break;
        }
		
        bool neg = false;
		
        if(s[i] == '-') {
            neg = true;
            i++;
        }
        else if(s[i] == '+') i++;
        
        string str = "";
        
        while(i < n) {
            if(s[i] != '0') break;
            else i++;
        }
        
        while(i < n) {
            if(s[i] <= '9' && s[i] >= '0')
            {
                str += s[i];
            }
			
            else break;
            i++;
        }

        long long res = 0;
        bool ovf = false;
        int p = 0;
		
        for(int i = str.size() - 1; i >= 0; --i) {
            int val = str[i] - '0';
            res += val * pow(10,p);
            p++;
			
            if((p > 10) or res > INT_MAX) {
                ovf = true; 
                break;
            }
        }
		
        if(ovf) {
            if (neg) return INT_MIN;
            else return INT_MAX;
        }
		
        if (neg) return -res;
        else return res;
    }
};