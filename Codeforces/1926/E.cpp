// Problem: E. Vlad and an Odd Ordering
// Contest: Codeforces - Codeforces Round 928 (Div. 4)
// URL: https://codeforces.com/contest/1926/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	int n, k; cin >> n >> k;
	int iter = 1;
	while (true) {
		if (k <= (n + 1)/2) {
			cout << iter * (2 * k - 1) << endl;
			break;			
		}
		else {
			iter *= 2;
			k -= (n + 1)/2;
			n -= (n + 1)/2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}