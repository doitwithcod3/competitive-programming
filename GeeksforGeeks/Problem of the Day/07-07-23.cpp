// Question Link-
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long a[], long long b[], int n, int m) 
        { 
            int i = n - 1, j = 0;
            while (i >= 0 && j < m) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                    i--, j++;
                }
                else break;
            }
            
            sort(a, a+n);
            sort(b, b+m);
        } 
};

int main() {
    Solution s;
    int n, m; cin >> n >> m;
    long long a[n], b[m];

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    s.merge(a, b, n, m);

    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    for (int i = 0; i < m; ++i) cout << b[i] << " "; cout << endl;

    
}
