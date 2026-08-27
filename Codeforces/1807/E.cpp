// Problem: E. Interview
// Contest: Codeforces - Codeforces Round 859 (Div. 4)
// URL: https://codeforces.com/contest/1807/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;


int query(int start, int end, vector<int> &a, int &sum) {
	cout << "? " << end - start + 1;
	for (int i = start; i <= end; ++i) {
		sum += a[i];
		cout << " " << i + 1;
	}
	cout.flush();
	int res; cin >> res;
	return res;
}
void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int start = 1, end = n, ans = -1;
	while (start <= end) {
		int mid = (start + end) >> 1;
		
		int expectdSum = 0;
		int check = query(start, mid, a, expectdSum);
		if (check > expectdSum) {
			ans = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	cout << "! " << ans << endl;
	cout.flush();
}

int main() {
	// ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}