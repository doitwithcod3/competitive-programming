// Problem: D. Unfair Game
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// You should not stalk like this :P 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define all(s) (s).begin(), (s).end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int neginf = -2e18;
const int inf = 2e18;
const int MOD = 1e9+7; 

unsigned int C[35][35];

void precomp() {
	for (int i = 0; i < 35; ++i) {
        C[i][0] = 1;
        C[i][i] = 1;
    }

    for (int n = 1; n < 35; ++n) {
        for (int r = 1; r < n; ++r) {
            C[n][r] = C[n - 1][r - 1] + C[n - 1][r];
        }
    }
}


void testcase() {
	int n, k; cin >> n >> k;
	int ans = 0;
	// finding all the numbers which can be converted into 0 within k moves.
	for (int i = 1; i <= min((long long) (32), k); ++i) {
		int atmaxones = k - i;
		int spaces = i - 1;
		for (int ii = 0; ii <= min(atmaxones, spaces); ++ii) {
 			cout << "space = " << spaces << " ii = " << ii << " = " << C[spaces][ii] << endl;
 			ans += C[spaces][ii];
 		}
	}
	cout << n - ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	precomp();
	// cout << fixed << setprecision(15);
	while (t--) {
		testcase();
	}
	return 0;
}