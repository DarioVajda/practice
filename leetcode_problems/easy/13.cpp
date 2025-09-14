class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = { {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

        int n = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i < s.size()-1 && values[s[i]] < values[s[i+1]]) {
                n -= values[s[i]];
            }
            else {
                n += values[s[i]];
            }
        }
        return n;
    }
};
