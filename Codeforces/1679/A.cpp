// URL: https://codeforces.com/contest/1679/problem/A
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
	if (n == 2 || n % 2 == 1) {
		cout << "-1\n";
		return;
	} 
	int minx, miny;
	int maxx, maxy;
	
	minx = n / 6;
	int rem = n % 6;
	if (rem == 0) {
		miny = 0;
	}
	else if (rem == 2) {
		minx--;
		miny = 2;
	}
	else { // rem == 4
		miny = 1;
	}
	
	maxx = n / 4;
	rem = n % 4;
	if (rem == 0) {
		maxy = 0;
	}
	else {
		maxx--;
		maxy = 1;
	}
	
	cout << minx + miny << " " << maxx + maxy << endl;
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