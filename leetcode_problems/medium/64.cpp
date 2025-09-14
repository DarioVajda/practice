class Solution {
public:
    int minPathSum_dijkstra_slow(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        pq.push({-grid[0][0], {0, 0}});

        pair<int, pair<int, int>> top;
        int r, c, sum;
        while(!pq.empty()) {
            top = pq.top(); pq.pop();
            sum = top.first;
            r = top.second.first;
            c = top.second.second;

            if(visited[r][c]) continue;
            visited[r][c] = true;
            // cout << r << ' ' << c << ' ' << sum << '\n';

            if(r == grid.size()-1 && c == grid[0].size()-1) return -sum;

            if(r < grid.size()-1 && !visited[r+1][c]) pq.push({ sum-grid[r+1][c], {r+1, c} });
            if(c < grid[0].size()-1 && !visited[r][c+1]) pq.push({ sum-grid[r][c+1], {r, c+1} });
        }
        return -1;
    }

    // dynamic programming approach
    // dist[i][j] = g[i][j] + min(dist[i-1][j], dist[i][j-1])
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 1; i < m; ++i) g[i][0] += g[i-1][0]; // calculate values for the first row
        for (int j = 1; j < n; ++j) g[0][j] += g[0][j-1]; // calculate values for the first column
        for (int i = 1; i < m; ++i)                       // iterate over all other rows and columns
            for (int j = 1; j < n; ++j)
                g[i][j] += min(g[i-1][j], g[i][j-1]);
        return g[m-1][n-1];
    }
};
