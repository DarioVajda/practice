class Solution {
public:
    int find_root(long long x, long long min, long long max) {
        if(x == 0 || x == 1) return x;


        long long mid = (min+max)/2;

        if(min > max) return min;

        if((mid+1)*(mid+1) < x) {
            return find_root(x, mid, max);
        }
        else if((mid+1)*(mid+1) == x) {
            return mid+1;
        }
        else if((mid+1)*(mid+1) > x && mid*mid <= x ) {
            return mid;
        }
        else {
            return find_root(x, min, mid);
        }
    }

    int mySqrt(int x) {
        return find_root(x, 1, x);
    }
};
