// Problem: B. Kuriyama Mirai's Stones
// Contest: Codeforces - Codeforces Round 248 (Div. 2)
// URL: https://codeforces.com/problemset/problem/433/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n; cin >> n;
	vector<long long int> a(n + 1, 0), b(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		a[i + 1] = a[i] + b[i];
	}
	sort(b.begin(), b.end());
	
	vector<long long int> pb(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		pb[i + 1] = pb[i] + b[i];
	}
	
	int q; cin >> q;
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 1) cout << a[r] - a[l - 1] << endl;
		else cout << pb[r] - pb[l - 1] << endl; 
	}
	return 0;
}