// Question Link-
// https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int>>&a, int n)
    { 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i != j) {
                    swap(a[i][j], a[j][i]);
                }
            }
        } 
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    s.transpose(a, n);

    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < (int) a[i].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    
}