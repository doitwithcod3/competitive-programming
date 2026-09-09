// URL: https://codeforces.com/contest/2259/problem/C
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	bool onefound = false;
	for (int i = 0; i < n; ++i) {
		onefound = onefound | a[i] == 1;
		if (onefound) break;
		if (a[i] == -1) {
			a[i] = 1;
			break;
		}
	}
	onefound = false;
	for (int i = n - 1; i >= 0; --i) {
		onefound = onefound | a[i] == 1;
		if (onefound) break;
		if (a[i] == -1) {
			a[i] = 1;
			break;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) cout << "0 ";
		else cout << a[i] << " ";
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