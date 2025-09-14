class Solution {
public:
    int climbStairs(int n) {
        int r_i_minus_1 = 1;
        int r_i = 1;
        for(int i = 1; i < n; i++) {
            r_i = r_i_minus_1 + r_i;
            r_i_minus_1 = r_i - r_i_minus_1;
        }
        return r_i;
    }
};
