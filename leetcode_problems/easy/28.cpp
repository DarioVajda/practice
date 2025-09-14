class Solution {
public:
    bool equalStrings(string s1, string s2) {
        if(s1.size() < s2.size()) return false;
        for(int i = 0; i < s2.size(); i++) {
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }

    int strStr_prev(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        
        for(int i = 0; i < haystack.size()-needle.size()+1; i++) {
            cout << i << ' ' << haystack.substr(i, haystack.size()) << ' ' << needle << endl;
            if(equalStrings(haystack.substr(i, haystack.size()), needle)) return i;
        }
        return -1;
    }

    vector<int> lps(string s) {
        int n = s.size();
        if(n == 0) return {};

        vector<int> res(n, 0);
        int len = 0, i = 1;
        while(i < n) {
            if(s[i] == s[len]) {
                len++;
                res[i] = len;
                i++;
            }
            else {
                if(len == 0) {
                    res[i] = 0;
                    i++;
                }
                else {
                    len = res[len-1];
                }
            }
        }
        return res;
    }

    int strStr(string haystack, string needle) {

        vector<int> needle_lps = lps(needle);
        // for(auto e: needle_lps) {
        //     cout << e << ' ';
        // }
        // cout << endl;

        int n = haystack.size(), m = needle.size();

        if(m > n) return -1;

        int i = 0, j = 0;

        while(i < n) {

            // cout << i << ' ' << j << endl;
            if(haystack[i] == needle[j]) {
                // cout << "increase i, j" << endl;
                j++;
                i++;
                if(j == m) break;
            }
            else if(j > 0) {
                // cout << "decrease j" << endl;
                j = needle_lps[j-1];
            }
            else {
                // cout << "increase i" << endl;
                i++;
            }
        }
        return (j == m) ? i-j : -1;
    }
};
