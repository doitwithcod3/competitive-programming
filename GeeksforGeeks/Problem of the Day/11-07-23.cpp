// Question Link-
// https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1#include <bits/stdc++.h>
// ---- YOU SHOULD DO IT YOURSELF. THIS QUESTION IS STANDARD ONE. TRY YOURSELF FIRST ----
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

class Solution
{
    public:
    
    int elementsAtMN(int m, int n) {
        return m*n - (max(0, m - 2) * max(0, n - 2));
    }
    
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        // cout << "N = " << n << " M = " << m << endl;
        int dpt = 0;
        int ele = elementsAtMN(m, n);
        // cout << "Ele = " << ele << endl;
        while (k > ele) {
            k -= ele;
            dpt++;
            ele = elementsAtMN(m - 2*dpt, n - 2*dpt);
        }
        k--;
        // Upar agar change hoga to vo sirf DPT me Coordinates issue agar aya to.
        // cout <<  "D = " << dpt << " K = " << k << endl;
        if (k < m - 2*dpt - 1) return a[dpt][k + dpt];
        
        k -= (m - 2*dpt - 1);
        // cout <<  "D = " << dpt << " K = " << k << endl;
        if (k < n - 2*dpt - 1) return a[k + dpt][m - dpt - 1];
        
        k -= (n - 2*dpt - 1);
        // cout <<  "D = " << dpt << " K = " << k << endl;
        if (k < m - 2*dpt - 1) return a[n - 1 - dpt][m - 1 - k - dpt];
        
        k -= (m - 2*dpt - 1);
        // cout <<  "D = " << dpt << " K = " << k << endl;
        return a[n - k - 1 - dpt][dpt];
    }
};

int main() {
    Solution s;
    int n, m, k; cin >> n >> m >> k;
    int a[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    cout << s.findK(a, n, m, k) << endl;
}