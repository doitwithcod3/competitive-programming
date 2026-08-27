#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	
	int n; cin >> n;
	int ar[] = {0, 1, 2, 3};
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 0; i < n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		swap(ar[a], ar[b]);
		
		if (ar[c] == 1) ++ans1;
		if (ar[c] == 2) ++ans2;
		if (ar[c] == 3) ++ans3;
	}
	cout << max(max(ans1, ans2), ans3) << endl;
	return 0;
}