// URL: https://codeforces.com/contest/2259/problem/D
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
	vector<array<int, 2>> a(n);
	for (int i = 0; i < n; ++i) {
		int ele; cin >> ele;
		a[i] = {ele, i};
	}
	sort(all(a));
	string ans(n, 'A');
	vector<int> mex(3, 0);
	for (auto [ele, index] : a) {
		if (mex[0] == ele) {
			ans[index] = 'A';
			mex[0]++;
		}
		else if (mex[1] == ele) {
			ans[index] = 'B';
			mex[1]++;
		}
		else if (mex[2] == ele) {
			ans[index] = 'C';
			mex[2]++;
		}
	}
	
	if (mex[1] == 0 && mex[2] == 0 && mex[0] != 0) {
		cout << "NO\n";
		return;
	}
	if ((mex[0] + mex[1] + mex[2]) >= (2 * mex[0])) {
		cout << "YES\n";
		cout << ans << endl;
		return;
	}
		
	for (auto [ele, index] : a) {
		if (ele > mex[2]) {
			ans[index] = 'C';
		}
	}
	cout << "YES\n";
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