/*
ID: chshivm1
LANG: C++
TASK: test
*/
 
#include <bits/stdc++.h>
#define eb emplace_back      
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using namespace std;
using ll = long long;
 
const int zero =  0.0000000001;
const int MOD = 1e9 + 7;
const int intmax = INT_MAX;
const long long llmax = LONG_LONG_MAX;
const int intmin = INT_MIN;
const long long llmin = LONG_LONG_MIN;
 
 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
 
// Doesnot works on all Negative
int kedane(vector<int> &array, int n) {    
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    return best;
}   
 
// Tested
bool isPresent(int ele, vector<int>& a) {  
    int i = 0, j = a.size() - 1;
    int mid;
 
    while (i <= j) {
        mid = (i + j)/2;
        if (a[mid] == ele) return true;
        else if (a[mid] < ele) i = mid + 1;
        else j = mid - 1;
    }
    return false;
}
 
int powof2(int i) {
    return (1 << i);
} 
 
//------------- NUMBER THEORY -------------//
int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}
 
int mmi(int a, int m) {
    return binpow(a, m-2, m);
}
 
int nCr(int n, int r) {
    if (n < r) return 0;
    r = min(n-r, r);
    int num = 1, deno = 1;
    for (int i = 1; i <= r; ++i) {
        num = (num * 1LL * (n-i+1)) % MOD;
        deno = (deno * 1LL * i) % MOD;
    } 
    deno = (deno * 1LL * r+1) % MOD;
    return (num * 1LL * mmi(deno, MOD)) % MOD;
}
 
long long gcd(long long a, long long b) {
    if (!a) return b;
    return gcd(b%a, a);
}
 
double getRoot(double a, double b, double c) {
    return 0;
}
// ---------------------- Number Theory Ends ---------------------- //
 
class SGTree {
    vector<ll> tree;
 
public: 
    SGTree(int n) {
        tree.resize(4*n + 1);
    }
 
    long long build(int index, int l, int r, vector<int>& arr) {
        if (l == r) return tree[index] = arr[l];
 
        int mid = (l + r) >> 1;
        ll left = build(2*index + 1, l, mid, arr);
        ll right = build(2*index + 2, mid + 1, r, arr);
 
        return tree[index] = left + right;
    }
 
    void update(int ind, int l, int r, int atIndex, int setVal) {
        if (l == r) {
            tree[ind] = setVal;
            return;
        }
 
        int mid = (l + r) >> 1;
        if (atIndex <= mid) update(2*ind + 1, l, mid, atIndex, setVal);
        else update(2*ind + 2, mid + 1, r, atIndex, setVal);
 
        tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
    }
 
    long long query(int ind, int low, int high, int ql, int qh) {
        // out of range (returning INTMAX for minimum SubQuery only.)
        if (qh < low || high < ql) return 0;
    
        // Proper Subset
        if (ql <= low && high <= qh) return tree[ind];
        
        int mid = (low + high) >> 1;
        long long ans1 = query(2*ind + 1, low, mid, ql, qh);
        long long ans2 = query(2*ind + 2, mid + 1, high, ql, qh);
 
        return ans1 + ans2;
    }
    // inline void print() {
    //     for (auto it : tree) cout << it << " "; cout << endl;
    // }
};
// Segment tree ends.
 
void testcase() {
    int n, q; cin >> n >> q;
    vi a(n);
    for(int i = 0;i < n; ++i) cin >> a[i];
    SGTree st(n);
 
    st.build(0, 0, n - 1, a);
    // st.print();
    while (q--) {
        int type; cin >> type;
        if (type == 2) {
            int l, r; cin >> l >> r;
            cout << st.query(0, 0, n-1, l - 1, r - 1) << endl;
        }
        else {
            int ind, val; cin >> ind >> val;
            st.update(0, 0, n-1, ind - 1, val);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}