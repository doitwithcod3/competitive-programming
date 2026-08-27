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
const int mod = 1e9+7; 

int divisors (int num) {
	int res = 0;
	for (int i = 1; i * i <= num; ++i) {
		if (num % i == 0) res = res + 1 + (num / i != i);
	}
	return res;
}

bool calc(int k, int maxbit, int range) { 
	// cout << "For k = " << k << " maxbit = " << maxbit << " Range = " << range << "\n";
	bitset<32> mask; 
	int iter = maxbit - 1, bit = 1;
	for (int i = 0; i < maxbit / k; ++i) {
		for (int j = 0; j < k; ++j) {
			mask[iter--] = bit;
		}
		bit ^= 1;
	}
	if (mask.to_ullong() <= range) return true;
	return false;
}

int construct (int maxbit, int range) {
	int res = 0;
	for (int i = 1; i * i <= maxbit; ++i) {
		if (maxbit % i == 0) {
			res += calc(i, maxbit, range);
			if (maxbit / i != i) res += calc(maxbit/i, maxbit, range);
		}
	}
	// cout << "for maxbit = " << maxbit << " Res = " << res << endl;
	return res;
}

int calcpattern(int num) {
	int bits = ceil(log2(num + 1));
	// cout << "bits = " << bits << endl; 
	int ans = 0;
	for (int i = 1; i < bits; ++i) {
		ans += divisors(i);
	}
	ans += construct(bits, num);
	return ans;
}

void testcase() {
	int l, r; cin >> l >> r;

	auto R = calcpattern(r);
	auto L = calcpattern(l - 1);
	cout << R -  L << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	// cout << fixed << setprecision(15);
	while (t--) {
		testcase();
	}
	return 0;
}