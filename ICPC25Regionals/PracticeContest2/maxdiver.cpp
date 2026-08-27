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
	map<int, int> map;
	for (int i = 0; i < n; ++i) {
		int ele; cin >> ele;
		map[ele]++;
	}
	priority_queue<int> pq;
	for (auto it : map) {
		pq.push(it.second - 1);
	}
	
	while (!pq.empty() && k--) {
		int val = pq.top(); pq.pop();
		val -= 1;
		if (val >= 1) pq.push(val);
	}
	int similarcount = 0;
	while (!pq.empty()) {
		int top = pq.top(); pq.pop();
		similarcount += (top * (top + 1)) >> 1;
	}
	
	cout << n * (n - 1) / 2 - similarcount << endl;
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