class Solution {
public:
    int lengthOfLastWord(string s) {
        bool first_spaces = s[s.size()-1] == ' ';
        int res = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(first_spaces && s[i] == ' ') continue;

            if(s[i] != ' ') {
                res++;
                first_spaces = false;
            }
            else break;
        }
        return res;
    }
};
