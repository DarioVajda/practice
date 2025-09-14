class Solution {
public:

    string rle(string s) {
        if(s.size() == 0) return "";
        string s_0{s[0]};

        if(s.size() >= 3 && s[0] == s[1] && s[1] == s[2]) return "3"+s_0+rle(s.substr(3, s.size()-3));
        if(s.size() >= 2 && s[0] == s[1]) return "2"+s_0+rle(s.substr(2, s.size()-2));
        return "1"+s_0+rle(s.substr(1, s.size()-1));
    }

    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";

        return rle(countAndSay(n-1));
    }
};
