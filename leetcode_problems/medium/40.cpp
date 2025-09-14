class Solution {
public:
    void recursive_combinationSum(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& ans, vector<bool>& used) {
        if(target == 0) {
            ans.push_back(path);
        }
        if(target < 0) return;

        int n = candidates.size();

        for(int i = start; i < n; i++) {
            if(candidates[i] > target) break;
            if(i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) continue;
            
            path.push_back(candidates[i]); used[i] = true;
            recursive_combinationSum(candidates, target-candidates[i], i+1, path, ans, used);
            path.pop_back(); used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(candidates.size(), false);

        recursive_combinationSum(candidates, target, 0, path, ans, used);
        return ans;
    }
};
