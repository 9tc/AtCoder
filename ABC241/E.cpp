#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9
#define LLINF (long long)1e12
#define MOD (int)1e9+7
#define PI 3.141592653589
#define PB push_back
#define F first
#define S second

#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define Graph vector<vector<int> >
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int> > //VVI a(n, vector<int>(m));
#define VPII vector<pair<int,int> >

#define DDD fixed<<setprecision(10)

template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
T GCD(T a, T b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
	return (a * b) / GCD(a, b);
}

using namespace std;
using namespace atcoder;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  VI pre(n, -1);

  vector<ll> s(n, 0);
  pre[0] = 0;

  int t;
  int loop;

  ll ans;

  REP(i,n){
    s[i+1] = s[i] + a[s[i] % n];
    if(pre[s[i+1] % n] != -1){
      t = pre[s[i+1] % n];
      loop = i+1;
      break;
    }
    pre[s[i+1] % n] = i + 1;
  }

  if(k <= t) ans = s[k];
  else{
    int p = loop - t;
    ll x = s[loop] - s[t];
    ll a = (k - t - 1) / p;
    ll b = (k - t - 1) % p;
    ans = s[t + b + 1] + (a * x);
  }

  cout << ans << endl;
}
