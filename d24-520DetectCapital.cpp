class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool firstIsUpper = isupper(word[0]);
        bool shouldAllCapital = false;
        for (int i = 1; i < n; ++i) {
            char c = word[i];
            if (i == 1) {
                if (firstIsUpper && isupper(c)) shouldAllCapital = true;
                else if (!firstIsUpper && isupper(c)) return false;
            } else if ( (shouldAllCapital && islower(c)) || 
                        (!shouldAllCapital && isupper(c)) ) return false;
        }
        return true;
    }
};