class Solution {
public:
    int binary_search(vector<int>& nums, int target, int start, int end) {
        // looking at range [start, end]
        if(start > end) return start;

        int middle = (start + end) / 2;

        if(nums[middle] == target) return middle;
        else if(target < nums[middle]) return binary_search(nums, target, start, middle-1);
        else return binary_search(nums, target, middle+1, end);
    }

    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }
};
