class Solution {
public:

    int find_break(vector<int>& a, int l, int r) {
        if(l > r) return -1;
        
        int m = (l+r) / 2;
        // cout << l << ' ' << m << ' ' << r << endl;
        if(m == a.size()-1) return a.size()-1;

        if(m > 0 && a[m-1] > a[m]) return m-1;
        if(a[m] > a[m+1]) return m;

        if(a[m] > a[r]) return find_break(a, m+1, r);
        else return find_break(a, l, m-1);
    }

    int br_a(vector<int>&a, int i, int br) {
        return a[(i+br)%a.size()];
    }

    int binary_search(vector<int>& a, int target, int l, int r, int br) {
        if(l > r) return -1;

        int m = (l+r)/2;
        // cout << l << ' ' << m << ' ' << r << endl;

        if(br_a(a, m, br) == target) {
            // cout << "found" << endl;
            return (m+br) % a.size();
        }
        else if(br_a(a, m, br) > target) {
            // cout << "left" << endl;
            return binary_search(a, target, l, m-1, br);
        }
        else {
            // cout << "right" << endl;
            return binary_search(a, target, m+1, r, br);
        }
    }

    int search(vector<int>& a, int target) {
        int br = (find_break(a, 0, a.size()-1)+1)%a.size();
        // cout << br << endl;
        return binary_search(a, target, 0, a.size()-1, br);
    }
};
