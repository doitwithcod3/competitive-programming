// Problem: D. Vlad and Division
// Contest: Codeforces - Codeforces Round 928 (Div. 4)
// URL: https://codeforces.com/contest/1926/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

int toggleBits(int num) {
	return (num ^ INT_MAX);
}

void testcase() {
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int ele; cin >> ele;
		mp[ele]++;
	}
	int ans = n;
	int count = 0;
	for (auto it : mp) {
		int toggle = toggleBits(it.first);
		count += min(it.second, mp[toggle]);
	}
	cout << ans - count / 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}
