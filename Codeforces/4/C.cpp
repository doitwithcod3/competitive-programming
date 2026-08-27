// Problem: C. Registration system
// Contest: Codeforces - Codeforces Beta Round 4 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/4/C
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	map<string, int> map;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string a; cin >> a;
		if (map.find(a) == map.end()) {
			cout << "OK\n";
		}
		else cout << a << map[a] << endl;
		
		map[a]++;
	}	
	return 0;
}