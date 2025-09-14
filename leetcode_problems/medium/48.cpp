class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size(), temp;

        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < (n+1)/2; j++) {
                temp = m[n-1-j][i];
                m[n-1-j][i] = m[n-1-i][n-1-j];
                m[n-1-i][n-1-j] = m[j][n-1-i];
                m[j][n-1-i] = m[i][j];
                m[i][j] = temp;
            }
        }
    }
};
