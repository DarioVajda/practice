class Solution {
public:
    int uniquePaths(int m, int n) {
        // result is "m+n-1 choose n-1" = (m+n)/n * (m+n-1)/(n-1) * ... * (m+1)/1

        m--; n--;
        int bigger = max(m, n);
        n = min(m, n); m = bigger;
        double res = 1;
        for(int i = 1; i <= n; i++) {
            res *= (double)(m+i)/(double)i;
            // cout << m+i << '/' << i << "->" << res << '\n';
        }
        cout << res << endl;
        return (int)round(res);
    }
};
