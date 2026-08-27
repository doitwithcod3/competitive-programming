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



int getindex(string &a, char ch) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == ch) return i;
	} 
	return -1;
}
void testcase() {
	string a; cin >> a;
	string b; cin >> b;
	
	int fco = getindex(a, b[0]); //firstCharOccurence 
	if (fco == -1) {
		cout << "-1\n";
		return;
	}
	cout << a.substr(fco + 1, a.size() - fco) << " " << b.substr(1, a.size() - 1) << endl;
	// return subsequence(a.substr(fco + 1, a.size() - fco), b.substr(1, a.size() - 1));
	 
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