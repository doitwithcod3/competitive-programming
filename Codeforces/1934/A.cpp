// Problem: A. Too Min Too Max
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int one = a[0], two = a[n - 1];
	int three = a[1], four = a[n - 2];
	
	cout << abs(one - two) + abs(two - three) + abs(three - four) + abs(one - four) << endl;
	 	
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}