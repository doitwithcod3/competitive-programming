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

void print(string& a, int k) {
    for (char ch : a) {
        for (int i = 0; i < k; ++i) {
            cout << ch;
        }
    }
    cout << endl;
}


void testcase() {
    int n, m, k; cin >> n >> m >> k;
    string a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            print(a[i], k);
        }
    }
}
/*

*/
int main() {
    ios_base::sync_with_stdio(false);

    //#ifndef ONLINE_JUDGE
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    //#endif
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}