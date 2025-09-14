#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int start = 0, longest = 0, n=s.size();
        for(int i = 0; i < n; i++) {
            start = max(start, last_seen[s[i]] + 1);
            last_seen[s[i]] = i;
            longest = max(longest, i-start+1);
        }
        return longest;
    }
};
