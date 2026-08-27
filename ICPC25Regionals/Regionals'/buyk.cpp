/*Akshay_Adak_289*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
//*******************************************************************
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
#define ll long long
#define dd double
#define sp setprecision
#define fwd(i,a,b) for(ll i=a;i<b;i++)
#define ubd(v,x) upper_bound(v.begin(),v.end(),x)-v.begin()
#define lbd(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()
#define ff first
#define ss second
#define sort(x) sort(x.begin(),x.end())
#define rev(x) reverse(x.begin(),x.end())
#define pb push_back
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define vlp vector<pair<ll,ll>>
#define vpq priority_queue<ll>
#define vqq  priority_queue<ll,vector<ll>,greater<ll>>
#define vpqq priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, compare> 
#define mod  1000000007     //998244353
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
//***************************************************


//***************************************************
void solve()
{
  ll n,k; cin>>n>>k; vll v(n+1); fwd(i,1,n+1) cin>>v[i]; v[0]=0;
  sort(v);
  vll ans(n+1),pre(n+1);
  pre[0]=0; ans[0]=0;
  fwd(i,1,n+1) pre[i]=pre[i-1]+v[i];
  
  for(int i=1;i<=k;i++) ans[i]=pre[i];
  for(int i=k+1;i<=n;i++){
    ll here = ans[i-k-1];
    ll sum = pre[i] - pre[i-k-1];
    sum-=v[i-k];
    here+=sum;
    ans[i]=here;
  }
  fwd(i,1,n+1) cout<<ans[i]<<" ";
  
  
}

//****************************************************
int main()
{
  fastread();
                 w(x){ solve();cout<<endl;  }    
         //         solve();  
}


