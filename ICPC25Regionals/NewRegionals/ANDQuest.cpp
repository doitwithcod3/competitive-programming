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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	
	vector<int> indices;
	int overalland = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if ((a[i] & k) == k) {
			indices.push_back(i + 1);
			overalland = (overalland & a[i]);
		}
	}
	if (overalland == k) {
		cout << "YES\n" << indices.size() << endl;
		for (auto it: indices) cout << it << " "; cout << endl;		
	}
	else cout << "NO\n";
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