class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans = {intervals[0]};
        int len=1;
        for(const auto& interval: intervals) {
            if(ans[len-1][1] >= interval[0]) ans[len-1][1] = max(ans[len-1][1], interval[1]);
            else {
                ans.push_back(interval);
                len++;
            }
        }
        return ans;
    }
};
