class Solution {
public:
    vector<vector<int>> recursive_combinationSum(vector<int>& candidates, int target, int start) {
        if(target == 0) return {{}}; 
        if(target < 0) return {};

        vector<vector<int>> combinations, curr;
        int n = candidates.size();
        for(int i = start; i < n; i++) {
            if(candidates[i] > target) continue;
            curr = recursive_combinationSum(candidates, target-candidates[i], i);
            for(int j = 0; j < curr.size(); j++) {
                curr[j].push_back(candidates[i]);
            }
            combinations.insert(combinations.end(), curr.begin(), curr.end());
        }
        return combinations;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return recursive_combinationSum(candidates, target, 0);
    }
};
