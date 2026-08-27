// Problem: A: Walk the Line
// Contest: Meta Coding Competitions - Meta Hacker Cup 2024 Practice Round
// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/A
// Memory Limit: 1024 MB
// Time Limit: 360000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	if (n == 1) ans = a[0];
	else {
		int mini = *min_element(all(a));
		ans = mini * (2 * n - 3);
	}
	
	if (ans > k) cout << "NO";
	else cout << "YES";
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}
	return 0;
}