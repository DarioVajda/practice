class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, long long target) {
        int n = a.size();
        sort(a.begin(), a.end());

        long long curr_target, l, r, diff, temp;
        vector<vector<int>> res;
        for(int i = 0; i < n-3; i++) {
            for(int j = i+1; j < n-2; j++) {
                if(i > 0 && a[i] == a[i-1]) continue;
                if(j > i+1 && a[j] == a[j-1]) continue;

                curr_target = target-a[i]-a[j];
                l = j+1;
                r = n-1;

                while(l < r) {
                    diff = a[l] + a[r] - curr_target;
                    if(diff < 0) l++;
                    else if(diff > 0) r--;
                    else {
                        res.push_back({a[i], a[j], a[l], a[r]});

                        temp = a[l];
                        while(l < r && a[l] == temp) l++;
                        temp = a[r];
                        while(l < r && a[r] == temp) r--;
                    }
                }
            }
        }
        return res;
    }
};
