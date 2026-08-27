// Problem: D - Forbidden List 2
// Contest: AtCoder - AtCoder Beginner Contest 440
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

void testcase() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(all(a));
	
	for (auto it : a) cout << it << " "; cout << endl;

	for (int i = 0; i < q; ++i) {
		int k, comp; cin >> k >> comp;
		
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		testcase();
	}
	return 0;
}