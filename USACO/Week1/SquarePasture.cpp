#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	
	int a, b, c, d; cin >> a >> b >> c >> d;
	int p, q, r, s; cin >> p >> q >> r >> s;
	
	int minH = min(min(q, b), min(d, s)), minB = min(min(p, r), min(a, c));
	int maxH = max(max(q, b), max(d, s)), maxB = max(max(p, r), max(a, c));
	
	int side = max(maxH - minH, maxB - minB);
	cout << side * side << endl;
		
	return 0;
}