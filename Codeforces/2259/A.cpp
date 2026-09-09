// URL: https://codeforces.com/contest/2259/problem/A
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
	int n, k; cin >> n >> k;
	string a; cin >> a;
	
	int ans = 0;
	for (int i = 0; i < n; i += k) {
		bool haszero = false;
		for (int j = 0; j < k; ++j) {
			if (a[i + j] == '0') {
				haszero = true;
				break;
			}	
		}
		if (!haszero) ans++;
	}
	cout << ans << endl;
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
