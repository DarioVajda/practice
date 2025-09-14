class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l, r, sum;

        int temp, best;

        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            l = i+1;
            r = n-1;

            while(l < r) {
                sum = nums[i] + nums[l] + nums[r] - target;

                if(abs(sum) < abs(target - best)) best = sum + target;

                if(sum < 0) l++;
                else if(sum > 0) r--;
                else {
                    temp = nums[l];
                    while(l < r && nums[l] == temp) l++;

                    temp = nums[r];
                    while(l < r && nums[r] == temp) r--;
                }
            }
        }

        return best;
    }
};
