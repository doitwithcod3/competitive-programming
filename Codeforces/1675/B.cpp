// URL: https://codeforces.com/contest/1675/problem/B
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
	
	for (auto &it : a) cin >> it;
	
	int ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		int operation = 0;
		while (operation < 40 && a[i] >= a[i + 1]) {
			operation++;
			a[i] /= 2;
		}
		if (operation >= 40) {
			cout << "-1\n";
			return;
		}
		ans += operation;
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