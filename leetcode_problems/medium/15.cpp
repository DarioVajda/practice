class Solution {
public:
    void printMap(const unordered_map<int, vector<pair<int,int>>>& mp) {
        for (const auto& [key, vec] : mp) {
            cout << key << " -> [ ";
            for (const auto& p : vec) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << "]\n";
        }
    }

    vector<vector<int>> threeSum_slow(vector<int>& nums) {
        unordered_map<int, vector<pair<int, int> > > map; // val --> (i, j) such that "nums_i+nums_j+val == 0"
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // { -nums[i]-nums[j], {i, j} }
                if(map.count(-nums[i]-nums[j]) >= 1) {
                    map[-nums[i]-nums[j]].push_back({i, j});
                }
                else {
                    map[-nums[i]-nums[j]] = { {i, j} };
                }
            }
        }

        // printMap(map);

        vector<vector<int>> res;
        set<vector<int>> present;
        vector<int> triplet;
        for(int i = 0; i < n; i++) {
            if(map.count(nums[i]) > 0) {
                for(auto p: map[nums[i]]) {
                    // cout << i << ' ' << p.first << ' ' << p.second << endl;
                    if(i >= p.first) continue;
                    triplet = {nums[i], nums[p.first], nums[p.second]};
                    sort(triplet.begin(), triplet.end());
                    if (!present.count(triplet)) {
                        res.push_back(triplet);
                        present.insert(triplet);
                        // cout << "new" << endl;
                    }
                }
            }
        }
        return res;
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l, r, sum;

        vector<vector<int>> res;
        int temp;

        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            l = i+1;
            r = n-1;

            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];

                if(sum < 0) l++;
                else if(sum > 0) r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    temp = nums[l];
                    while(l < r && nums[l] == temp) l++;

                    temp = nums[r];
                    while(l < r && nums[r] == temp) r--;
                }
            }
        }

        return res;
    }
};
