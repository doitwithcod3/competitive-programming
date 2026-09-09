// URL: https://codeforces.com/problemset/problem/2256/B
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
	string a; cin >> a;
	
	auto inverse = [&] (char ch) -> char {
		return ch == '0' ? '1' : '0';
	};
	
	auto traverse = [&] (int index) -> void {
		char lastchar = '.';
		for (int i = index; i < n; i += 2) {
			if (a[i] != '?') lastchar = a[i];
			else {
				if (lastchar != '.') {
					a[i] = inverse(lastchar);
					lastchar = a[i];
				}
			}
		}
	};
	
	traverse(0);
	traverse(1);
	reverse(all(a));
	traverse(0);
	traverse(1);
	reverse(all(a));
	
	for (int i = 2; i < n; ++i) {
		if (a[i - 2] == a[i] && a[i] != '?') {
			cout << "0\n";
			return;
		}
	}
	int last = a[n - 1] == '?' ? 2 : 1;
	int seclast = a[n - 2] == '?' ? 2 : 1;
	
	cout << last * seclast << endl;
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