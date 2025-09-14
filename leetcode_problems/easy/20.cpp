class Solution {
public:
    bool isValid(string s) {
        vector<char> stack = {};
        for(auto c: s) {
            if((c == ')' || c==']' || c=='}') && stack.size() == 0) return false;
            if(
                c == ')' and stack[stack.size()-1] == '(' ||
                c == ']' and stack[stack.size()-1] == '[' ||
                c == '}' and stack[stack.size()-1] == '{'
            ) {
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        if(stack.size() > 0) return false;
        return true;
    }
};
