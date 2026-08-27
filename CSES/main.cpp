#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) (s).begin(), (s).end()

const int maxN = 2e5 + 2;
const int inf = 1e18;

vector<array<int, 2>> a(maxN);
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}
	sort(a.begin(), a.begin() + n);
	
	int ans = 1;
	map<int, int> index;
	for (int i = 0; i < n; ++i) {
		if (i != 0 && a[i - 1][1] > a[i][1]) ans++;
		index[a[i][1]] = i + 1;
	}
	
	for (auto it : index) cout << it.first << " " << it.second << endl;
	for (int i = 0; i < q; ++i) {
		int prev, now; cin >> prev >> now;
		
		// ans = ans - before + after;
		cout << ans << endl;
	}
	
	
}