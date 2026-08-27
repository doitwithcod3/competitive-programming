// Problem: C2. Potions (Hard Version)
// Contest: Codeforces - Codeforces Round 723 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1526/C2
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

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int positivesum = 0, positivecount = 0;
	vector<int> negs;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) positivesum += a[i], positivecount++;
		else negs.push_back(-a[i]);
	}
	
	sort(all(negs));
	for (int i = 1; i < negs.size(); ++i) {
		negs[i] = negs[i] + negs[i - 1];
	}
	
	int maxtake = upper_bound(all(negs), positivesum) - negs.begin();
	cout << maxtake + positivecount << endl;
		
	return 0;
}