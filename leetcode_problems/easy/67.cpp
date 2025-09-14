class Solution {
public:
    char get_i(string a, int i) {
        if(i < 0 || i >= a.size()) return 0;
        return a[i] == '0' ? 0 : 1;
    }

    string addBinary(string a, string b) {
        string res(max(a.size(), b.size()), '0');
        
        int carry = 0;
        int ai, bi;
        int size_a = a.size(), size_b = b.size();
        for(int i = max(size_a, size_b)-1; i >= 0; i--) {
            ai = get_i( a, i+ size_a - max(size_a, size_b) );
            bi = get_i( b, i+ size_b - max(size_a, size_b) );
            if(ai+bi+carry== 0) {
                res[i] = '0';
                carry = 0;
            }
            else if(ai+bi+carry== 1) {
                res[i] = '1';
                carry = 0;
            }
            else if(ai+bi+carry== 2) {
                res[i] = '0';
                carry = 1;
            }
            else {
                res[i] = '1';
                carry = 1;
            }
        }
        if(carry == 1) res.insert(0, "1");

        return res;
    }
};
