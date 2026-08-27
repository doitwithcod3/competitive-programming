/* Problem Link:
    https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473
*/

#include <bits/stdc++.h>
using namespace std;

int calc(int mid, int row, int col, vector<vector<int>> mat) {
    int result = 0;
    for (vector<int> vect : mat) {
        auto it = upper_bound(vect.begin(), vect.end(), mid);
        result += it - vect.begin();
    }
    return result;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int i = 1, j = 1e9;
    while (i <= j) {
        int mid = (i + j)/2;
        if (calc(mid, m, n, matrix) <= (m*n)/2) i = mid + 1;
        else j = mid - 1;
    }    
    return i;
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int> (n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    cout << median(a, m, n) << endl;
}