class Solution {
public:
    void nextPermutation(vector<int>& a) {
        // [1]
        // [1, 2], [2, 1]
        // [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]
        // [1, 2, 3, 4], [1, 2, 4, 3], [1, 3, 2, 4], [1, 3, 4, 2], [1, 4, 2, 3], [1, 4, 3, 2], [2, 1, 3, 4],...
        // [2, 4, 3, 1] ~~~> 2 | 1, 3, 4 ~~~> 3 | 1, 2, 4 -> [3, 1, 2, 4]

        // next[1, 2, 3, 4, 5, 9, 7, 8, 6, 0] == [1, 2, 3, 4, 5, 9, ...next[7, 8, 6] ]

        // 786 ~ 231 --> 312 ~ 867

        int n = a.size();
        if(n == 0) return;
        if(n == 1) return;
        if(n == 2) {
            a[0] = a[1] + a[0];
            a[1] = a[0] - a[1];
            a[0] = a[0] - a[1];
            return;
        }

        int tail = n-1; // index where the decreasing tail starts
        while(tail >= 1 && a[tail-1] >= a[tail]) {
            tail--;
        }
        // cout << tail << endl;

        int temp;
        for(int i = tail; i < (n+tail)/2; i++) {
            // cout << "swap " << i << ' ' << n-i-1+tail << endl;
            temp = a[i];
            a[i] = a[n-i-1+tail];
            a[n-i-1+tail] = temp;
        }
        if(tail == 0) return;
        if(tail == n-1) {
            temp = a[n-1];
            a[n-1] = a[n-2];
            a[n-2] = temp;
            return;
        }

        // for(int i = 0; i < n; i++) cout << a[i] << ' ';
        // cout << endl;

        int target = tail;
        tail--;
        while(a[target] <= a[tail]) target++;

        // cout << tail << ' ' << target << endl;

        temp = a[target];
        a[target] = a[tail];
        a[tail] = temp;
    }
};
