class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; // negative numbers are not palindromes
        if(x == 0) return true;
        
        vector<int> digits;
        while(x > 0) {
            digits.push_back(x%10);
            x/=10;
        }
        int l = digits.size();
        for(int i = 0; i <= l/2; i++) {
            if(digits[i] != digits[l-i-1]) return false;
        }
        return true;
    }
};
