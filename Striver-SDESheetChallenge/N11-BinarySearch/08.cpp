// Problem Link : https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

bool check (ll mid, vector<ll> &a, int c) {
    ll used = 1, val = a[0] + mid;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (val <= a[i]) {
            used++;
            val = a[i] + mid;
        }
    }
    // cout << " u = " << used;
    if (used >= c) return true;
    return false;
}

int main() {
  int tt; cin >> tt;
  while (tt--) {
    int n, c; cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));

    ll low = 0, high = 1e9 + 7;
    ll ans = -1;

    while (low <= high) {
        ll mid = (low + high) >> 1;
        // cout << low << " " << high;
        if (check(mid, a, c)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
        // cout << endl;
    }
    cout << ans << endl;
  }
}
