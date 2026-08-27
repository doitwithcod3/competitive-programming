/* Problem Link:
    https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems
*/

#include <bits/stdc++.h>
using namespace std;

int compare(long long num, long long pow, long long comparator) {
    long long result = num;
    for (int i = 1; i < pow; ++i) {
        result = result * num; 
        if (result > comparator) return 1;
    }
    if (result == comparator) return 0;
    return -1;
}

int NthRoot(int n, int m) {
    int i = 1, j = m;

    while (i <= j) {
        int mid = (i+j)/2;
        // cout << i << " - " << j << endl;
        int cmp = compare(mid, n, m); 
        if (cmp == 0) return mid;
        else if (cmp == -1) i = mid + 1;
        else j = mid - 1;
    }
    return -1;
}

int main() {
    int n, m; cin >> n >> m;
    cout << NthRoot(n, m) << endl;
}
