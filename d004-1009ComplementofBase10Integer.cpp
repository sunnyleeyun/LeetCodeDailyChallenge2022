class Solution {
public:
    int bitwiseComplement(int n) {
        string b;
        if (n == 0) b = "0";
        while (n != 0) {
            b.insert(0, n % 2 ? "1" : "0");
            n /= 2;
        }
        for (int i = 0; i < b.length(); ++i) {
            if (b[i] == '1') b[i] = '0';
            else b[i] = '1';
        }
        
        int res = 0;
        int index = 0;
        for (int i = b.length() - 1; i >= 0; --i) {
            if (b[i] == '1') res += pow(2, index);
            index++;
        }
        return res;
    }
};

// A genious solution which I don't entirely understand
class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        while (n > x) x = 2 * x + 1;
        return n ^ x;
    }
};