class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        string key;
        for(const string& s : strs) {
            key = s;
            sort(key.begin(), key.end());
            if(map.count(key)>0) map[key].push_back(s);
            else map[key] = {s};
        }
        
        vector<vector<string>> ans;
        for (const auto& pair : map) ans.push_back(pair.second);
        return ans;
    }
};
