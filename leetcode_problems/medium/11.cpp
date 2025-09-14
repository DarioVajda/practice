class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maks = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                maks = max(maks, height[l] * (r-l));
                l++;
            }
            else {
                maks = max(maks, height[r] * (r-l));
                r--;
            }
        }
        return maks;
    }
};
