// Problem: B. Binary Path
// Contest: Codeforces - Codeforces Round 930 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1937/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// You should not stalk like this :P 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define all(s) (s).begin(), (s).end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int neginf = -2e18;
const int inf = 2e18;
const int mod = 1e9+7; 


int get(vector<vector<int>> &dp, int i, int j) {
	if (i < dp.size() && j < dp[0].size()) return dp[i][j];
	return 1e8;
}

void testcase() {
	int n; cin >> n;
	string a[2];
	for (int i = 0; i < 2; ++i) cin >> a[i];
	
	vector<vector<int>> dp(2, vector<int> (n, 0));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = a[i][j] + min(get(dp, i - 1, j), get(dp, i, j - 1)) - '0';
		}
	}
	for (auto it : dp) {
		for (auto ii : it) cout << ii << " "; cout << endl;
	}
	cout << endl;
	
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	// cout << fixed << setprecision(15);
	while (t--) {
		testcase();
	}
	return 0;
}