#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
typedef long long ll;
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define all(s) (s).begin(), (s).end()
#define cntone(s) __builtin_popcountll(s)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int mod=1e9+7;
 
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second); }
void printa(vector<int>&v){for(auto i:v){cout<<i<<" ";}cout<<endl;}
void printmp(map<int,int>mp){for(auto i:mp){cout<<i.first<<" "<<i.second<<endl;}}
int binexpo(int a,int b){if(a>=mod){a%=mod;}int ans=1;while(b>0){if(b&1){ans=ans*a % mod;}a=a*a%mod;b>>=1;}return ans;}
int mInv(int n,int p){return binexpo(n, p - 2);}
int nCr(int n,int r){if(n<r){return 0;}if(r==0){return 1;}int fact[n+1];fact[0]=1;for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;return(fact[n]*mInv(fact[r],mod)%mod*mInv(fact[n-r],mod)%mod)%mod;}

bool check(int mid, string &a, string &b, vector<int> &arr) {
	string temp(b.size(), '*');
	for (int i = 0; i < mid; ++i) {
		temp[arr[i] - 1] = b[arr[i] - 1];
	}
	int i = 0, j = 0;
	while (i < a.size() && j < temp.size()) {
		if (a[i] == temp[j]) {
			i++, j++;
		}
		else j++;
	}
	if (i == a.size()) return true;
	return false;
}

void testcase() {
	int n; cin >> n;
	string a; cin >> a;
	int m; cin >> m;
	string b; cin >> b;
	
	vector<int> per(m);
	for (int i = 0; i < m; ++i) cin >> per[i];
	
	int ans = -1;
	int i = 0, j = b.size();
	while (i <= j) {
		int mid = (i + j) >> 1;
		if (check(mid, a, b, per)) {
			ans = mid;
			j = mid - 1;		
		}
		else i = mid + 1;
	}
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	
	while (t--) {
		testcase();
	}
	return 0;
}