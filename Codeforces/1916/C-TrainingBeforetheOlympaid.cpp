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
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	ll sum = a[0], odd = (a[0] % 2 == 1);
	cout << a[0] << " ";
	for (int i = 1; i < n; ++i) {
		sum += a[i];
		if (a[i] % 2 == 1) ++odd;
		cout << sum - ((odd / 3) + (odd % 3 == 1)) << " ";
	}
	cout << endl;
}
/*

*/
int main() {
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("C:\\Users\\doitwithcod3\\Documents\\code\\InputOutput\\input.txt", "r", stdin);
    freopen("C:\\Users\\doitwithcod3\\Documents\\code\\InputOutput\\output.txt", "w", stdout);
    #endif
    cout << fixed << setprecision(20);
    int t = 1;
    cin >> t;
    while (t--) {
        testcase();
    }
    #ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}