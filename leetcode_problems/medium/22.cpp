class Solution {
public:
    vector<string> apply_template(string prefix, vector<string> l1, string infix, vector<string> l2, string sufix) {
        vector<string> res;
        for(auto s1: l1) {
            for(auto s2: l2) {
                res.push_back(prefix+s1+infix+s2+sufix);
            }
        }
        return res;
    }

    vector<string> generateParenthesis(int n) {
        vector<vector<string>> table;
        vector<string> temp;
        for(int i = 0; i <= n; i++) {
            if(i == 0) {
                table.push_back({""});
            }
            else if(i == 1) {
                table.push_back({"()"});
            }
            else {
                table.push_back({});
                for(int j = 0; j <= i-1; j++) {
                    temp = apply_template("(", table[j], ")", table[i-j-1], "");
                    table[i].insert(table[i].end(), temp.begin(), temp.end());
                }
            }
            // cout << i << ": ";
            // for(auto s: table[i]) {
            //     cout << s << ", ";
            // }
            // cout << endl;
        }
        return table[n];
    }
};
