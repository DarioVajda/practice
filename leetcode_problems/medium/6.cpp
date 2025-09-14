class Solution {
public:
    // This runs in O(n*logn)
    string convert_slow(string s, int numRows) {
        if(numRows == 1) return s;

        int cycle_len = numRows * 2 - 2;
        int n = s.size(), remainder;
        vector<pair<char, int> > row(n, {'x', -1});
        for(int i = 0; i < n; i++) {
            row[i].first = s[i];
            remainder = i % cycle_len;
            if(remainder < numRows) {
                row[i].second = remainder;
            }
            else {
                row[i].second = cycle_len - remainder;
            }
        }

        stable_sort(row.begin(), row.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;  // sort ascending by age
        });
        string res(n, 'x');
        for(int i = 0; i < n; i++) res[i] = row[i].first;

        return res;
    }

    // This runs in O(n)
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || numRows >= n) return s;

        int cycle_len = numRows * 2 - 2, remainder;

        vector<vector<char> > rows(numRows, vector<char>());
        for(int i = 0; i < n; i++) {
            remainder = i % cycle_len;
            if(remainder < numRows) rows[remainder].push_back(s[i]);
            else rows[cycle_len - remainder].push_back(s[i]);
        }

        string res(n, 'x');
        int i = 0;
        for(auto row: rows) {
            for(auto c: row) {
                res[i] = c;
                i++;
            }
        }

        return res;
    }
};
