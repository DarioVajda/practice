class Solution {
public:

    long long divide_positive(long long a, long long b) {
        // cout << a << ' ' << b << endl;

        if(b > a) return 0;

        long long temp = b;
        long long count = 1;

        while(temp+temp <= a) {
            temp = temp + temp;
            count = count + count;
        }
        return count + divide_positive(a - temp, b);
    }

    int divide(long long a, long long b) {
        if(abs(b) > abs(a)) return 0;

        long long res;
        if((a < 0 && b < 0) || (a > 0 && b > 0)) res = divide_positive(abs(a), abs(b));
        else return res = -divide_positive(abs(a), abs(b));

        if(res < -pow(2, 31)) return -pow(2, 31);
        if(res > pow(2, 31)-1) return pow(2, 31)-1;
        return res;
    }
};
