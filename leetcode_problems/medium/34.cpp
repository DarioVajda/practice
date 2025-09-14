class Solution {
public:
    int binary_search_left(vector<int>& a, int t, int l, int r) {
        // cout << l << ' ' << r << endl;
        if(l > r) return -1;

        int m = (l+r)/2;

        if(a[m] < t) return binary_search_left(a, t, m+1, r);
        else if(a[m] == t && (m == 0 || a[m-1] != t)) return m;
        else if(a[m] == t) return binary_search_left(a, t, l, m);
        else return binary_search_left(a, t, l, m-1);
    }

    int binary_search_right(vector<int>& a, int t, int l, int r) {
        // cout << ' ' << l << ' ' << r << endl;
        if(l > r) return -1;

        int m = (l+r+1)/2;

        if(a[m] < t) return binary_search_right(a, t, m+1, r);
        else if(a[m] == t && (m == a.size()-1 || a[m+1] != t)) return m;
        else if(a[m] == t) return binary_search_right(a, t, m, r);
        else return binary_search_right(a, t, l, m-1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {binary_search_left(nums, target, 0, n-1), binary_search_right(nums, target, 0, n-1)};
    }
};
