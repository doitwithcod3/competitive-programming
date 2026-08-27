/*
ID: chshivm1
LANG: C++
TASK: test
*/

#include <bits/stdc++.h>    
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

void testcase() {
    string a[10];

    pair<int, int> B, R, L;
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }   

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (a[i][j] == 'B') {
                B.first = i;
                B.second = j;
            }
            if (a[i][j] == 'R') {
                R.first = i;
                R.second = j;   
            }
            if (a[i][j] == 'L') {
                L.first = i;
                L.second = j;   
            }
        }
    }
    // cout << R.first << " " << R.second << endl;
    // cout << L.first << " " << L.second << endl;
    // cout << B.first << " " << B.second << endl;

    int dis1 = abs(L.first - B.first);
    int dis2 = abs(L.second - B.second);

    if ((L.first == R.first && R.first == B.first)
        && (L.second < R.second && R.second < B.second || B.second < R.second && R.second < L.second)) {
        cout << dis1 + dis2 + 1;
    } 
    else if ((L.second == R.second && R.second == B.second)
        && (L.first < R.first && R.first < B.first || B.first < R.first && R.first < L.first))  {
        cout << dis1 + dis2 + 1;
    }
    else cout << dis1 + dis2 - 1;
}
/*

*/
int main() {
    ios_base::sync_with_stdio(false);

    //#ifndef ONLINE_JUDGE
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    //#endif
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}