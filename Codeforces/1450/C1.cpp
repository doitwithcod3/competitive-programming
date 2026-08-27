// Problem: C1. Errich-Tac-Toe (Easy Version)
// Contest: Codeforces - Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// Solved after Reading Editorial

#include <bits/stdc++.h>
using namespace std;

int n;  // InputSize

void testcase() {
	cin >> n;
	vector<vector<char>> a(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> a[i][j];
	}
	
	int count[3] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 'X') ++count[(i + j) % 3];
		}
	}
	
	int indexofMinCount;
	if (count[0] <= count[1] && count[0] <= count[2]) indexofMinCount = 0;
	else if (count[1] <= count[0] && count[1] <= count[2]) indexofMinCount = 1;
	else indexofMinCount = 2;
	// cout << "Index = " << indexofMinCount << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 'X') {
				if ((i + j) % 3 == indexofMinCount) cout << "O";
				else cout << "X";
			}
			else cout << a[i][j];
		}
		cout << endl;
	}
	
	
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}