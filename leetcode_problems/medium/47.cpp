class Solution {
public:
    void permute_recursive(vector<int>& nums, vector<int>& path, vector<vector<int>>& ans, vector<bool>& used) {
        if(path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true; path.push_back(nums[i]);
            permute_recursive(nums, path, ans, used);
            used[i] = false; path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        permute_recursive(nums, path, ans, used);

        return ans;
    }
};
