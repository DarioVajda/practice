class Solution {
public:
    double myPow(double x, long long n) {
        double res = 1;
        long long pos_n = abs(n);
        while(pos_n > 0) {
            if(pos_n%2) res *= x;
            x=x*x;
            pos_n/=2;
        }
        return (n>=0) ? res : 1/res;
    }
};
