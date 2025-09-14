class Solution {
public:
    long long reverse_positive(long long x) {
        long long res = 0, last_digit;
        while(x > 0) {
            last_digit = x % 10;
            res = 10*res + last_digit;
            x /= 10;
        }
        return res;
    }

    int reverse(int x) {
        long long MIN = -pow(2, 31), MAX = pow(2, 31) - 1;

        long long res;
        if(x < 0) {
            res = -reverse_positive(-((long long) x));
        }
        else {
            res = reverse_positive((long long) x);
        }

        return (res >= MIN && res <= MAX) ? res : 0;
    }
};
