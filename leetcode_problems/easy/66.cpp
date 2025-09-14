class Solution {
public:

    vector<int> recursive_plusOne(vector<int>& digits, int pos) {
        if(pos == -1) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        if(digits[pos] == 9) {
            digits[pos] = 0;
            return recursive_plusOne(digits, pos-1);
        }
        digits[pos] += 1;
        return digits;
    }

    vector<int> plusOne(vector<int>& digits) {
        return recursive_plusOne(digits, digits.size()-1);
    }
};
