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

int close(int a, int b, int c, int d, int p, int q, int r, int s) {
    int side1 = max(min(c, r) - max(a, p), 0);
    int side2 = max(min(d, s) - max(b, q), 0);

    return side1 * side2;
}

void testcase() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    int x5, y5, x6, y6; cin >> x5 >> y5 >> x6 >> y6;

    int area1 = abs(x2 - x1) * abs(y2 - y1);
    int area2 = abs(x4 - x3) * abs(y4 - y3);

    cout << area1 + area2 - close(x1, y1, x2, y2, x5, y5, x6, y6) - close(x3, y3, x4, y4, x5, y5, x6, y6);
}
/*

*/
int main() {
    ios_base::sync_with_stdio(false);

    //#ifndef ONLINE_JUDGE
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    //#endif
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}