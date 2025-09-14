class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int largest_sum=nums[0], trailing_sum=0, n=nums.size();

        for(int i = 0; i < n; i++) {
            trailing_sum += nums[i];
            trailing_sum = max(nums[i], trailing_sum);
            largest_sum = max(largest_sum, trailing_sum);
        }
        return largest_sum;
    }
};
