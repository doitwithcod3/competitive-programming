// You should not stalk like this :P 
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>
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

int arand(int maxval) {
	return 1 + (rand() % maxval);
}

long long solve(std::vector<int>& process_id, int divisor) {
    int n = process_id.size();
    unordered_map<int, int> freq;
    vector<int> ps(n + 1);
    long long sum = 0;
    long long ans = 0;
    ps[0] = 0;
    freq[0] = 1;
    for (int i = 0; i < n; ++i) {
        int cur = i + 1;
        sum += process_id[i];
        long long val = (sum - cur) % divisor;
        if (val < 0) val += divisor;
        ps[cur] = val;
        if (cur >= divisor) {
            int val_to_remove = ps[cur - divisor];
            freq[val_to_remove]--;
        }
        if (freq.count(val)) {
            ans += freq[val];
        }   
        freq[val]++;
    }
    return ans;
}

long long brute(vector<int> process_id, int divisor) {
    int n = process_id.size();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += process_id[j];
            int length = j - i + 1; 
            if ((sum % divisor) == length) {
                ans++;
            }
        }
    } 
    return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	srand(static_cast<unsigned int>(std::time(nullptr)));

	int test; cin >> test;
	for (int t = 0; t < test; ++t) {
		int n = arand(2000);
		int k = arand(20000);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = arand(100000);	
		}
		auto ans = solve(a, k);
		auto ans2 = brute(a, k);
		
		// cout << "For testcase\n";
		// cout << n << " " << k << endl;
		// for (auto it : a) cout << it << " "; cout << endl;
		if (ans != ans2) {
			cout << "Actual = " << ans2 << " Got = " << ans << endl;	
			break;		
		}
		else cout << "Works\n";
	}
	return 0;
}
