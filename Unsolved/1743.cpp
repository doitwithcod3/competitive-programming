// Problem: String Reorder
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1743
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string a; cin >> a;
	map<char, int> mp;
	for (auto it : a) mp[it]++;
	for (auto it : mp) cout << it.first << " " << it.second << endl;
	
}