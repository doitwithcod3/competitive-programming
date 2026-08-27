// Problem: A. Shuffle Party
// Contest: Codeforces - Codeforces Round 930 (Div. 2)
// URL: https://codeforces.com/contest/1937/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	long long int n; cin >> n;
	long long int num = 1;
	while (num * 2 <= n) num <<= 1;

	cout << num << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}