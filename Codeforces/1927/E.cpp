// Problem: E. Klever Permutation
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n, -1);
	int num = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			int count = 0;
			for (int j = i; j < n; j += k) {
				if (i % 2 == 0) a[j] = num++;		
				else ++count;
			}
			if (i % 2 != 0) {
				num += count;
				int temp = num;
				for (int j = i; j < n; j += k) {
					a[j] = --temp;
				}
			}
		}
	}
	for (auto it : a) cout << it << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}