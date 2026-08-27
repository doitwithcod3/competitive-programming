#include <bits/stdc++.h>
using namespace std;

void testcase() {
	string a; cin >> a;
	map<char, int> map;
	
	for (char ch : a) map[ch]++;

	for (auto it : map) {
		if (it.second >= 3) {
			cout << it.first << endl;
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}