// Problem: B. Yet Another Coin Problem
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
vector<int> arr = {15, 10, 6, 3, 1};
vector<int> dp(301, 1e9);

void precompp() {
	for (int ele : arr) {
		dp[ele] = 1;
	}
	for (int i = 2; i <= 300; ++i) {
		for (int ele : arr)
			if (i >= ele) dp[i] = min(dp[i], dp[i - ele] + dp[ele]);
	}
	// for (auto it : dp) cout << it << " "; cout << endl;
}

void testcase() {
	long long int n; cin >> n;
	if (n >= 299) {
		int init = (n - 100) / 15;
		cout << init + dp[n - (init * 15)] << endl;
	} 
	else cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	precompp();
	while (t--) {
		testcase();
	}
	return 0;
}