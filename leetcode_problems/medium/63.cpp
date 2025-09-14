class Solution {
public:
    long long get_next(vector<long long> dp, long long j) {
        if(j >= dp.size()-1) return 0;
        return dp[j+1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long long rows = obstacleGrid.size(), columns = obstacleGrid[0].size();
        vector<long long> dp(columns, 0);
        dp[columns-1] = 1;

        for(int i = rows-1; i >= 0; i--) {
            for(int j = columns-1; j >= 0; j--) {
                // cout << dp[j] << "-->";
                dp[j] = (dp[j]+get_next(dp, j)) * (1-obstacleGrid[i][j]);
                // cout << i << ' ' << j << ' ' << dp[j] << endl;
            }
        }
        return dp[0];
    }
};
