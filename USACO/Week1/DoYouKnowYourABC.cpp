#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int a[7];
	for (int i = 0; i < 7; ++i) cin >> a[i];
	sort(a, a + 7);
	
	cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << endl;
	return 0;
}