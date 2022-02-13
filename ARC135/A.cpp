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
using mint = modint998244353;

ll myceil(ll x){
  if(x % 2 == 1) return x / 2 + 1;
  else return x / 2;
}
ll myfloor(ll x){
  if(x % 2 == 1) return x / 2;
  else return x / 2;
}

map<ll, ll> memo;
ll f(ll x){
  if(memo.count(x)) {
    return memo[x];
  }
  ll t1 = myceil(x);
  ll t2 = myfloor(x);
  if(x * 1.0 / t2 < t1) return memo[x] = f(t1) * f(t2) % 998244353;
  else return memo[x] = x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	ll x;
  cin >> x;
  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 3;
  memo[4] = 4;

  cout << f(x) << endl;
}
