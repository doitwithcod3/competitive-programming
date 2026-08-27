// Problem: A. Against the Difference
// Contest: Codeforces - Codeforces Round 1046 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2135/A
// Memory Limit: 256 MB
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

int dfs(int index, map<int, vector<int>> &graph, vector<int> &a) {
	if (index >= a.size()) return 0;
	int nottake = dfs(index + 1, graph, a);
	int take = 0;
	
	int graphindex = lower_bound(all(graph[a[index]]), index) - graph[a[index]].begin();
	if (graphindex + a[index] - 1 < graph[a[index]].size()) 
		take = 1 + dfs(graph[a[index]][graphindex + a[index] - 1], graph, a);
	return max(take, nottake);
}

void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	map<int, vector<int>> graph;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		graph[a[i]].push_back(i);
	}
	for (auto it : graph) {
		cout << "for " << it.first << " = ";
		for (auto ele : it.second) cout << ele << " "; cout << endl;
	}
	cout << "working"
	auto ans = dfs(0, graph, a);
	cout << ans << endl << endl;
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