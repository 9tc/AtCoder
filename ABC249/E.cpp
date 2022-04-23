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

ll p;

ll f(ll n){
  if(n < 10) return 1;
  if(n < 100) return 2;
  if(n < 1000) return 3;
  return 4;
}

map<ll, ll> memo;
ll ff(ll n){
  if(n == 1) return 26;
  return memo[n] = 25 * ff(n-1) % p;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n >> p;

  vector<map<tuple<int,int,int>, int>> vm(2);
  vm[0][{1,0,1}]++; // 区切りの数, 暫定文字列の長さ, 最後の文字が連なる数
  REP(i,n-1){
    int it = i % 2;
    int nit = (i+1) % 2;

    for(auto m: vm[it]){
      tuple<int,int,int> pm = m.first;

      // 同じ記号の場合
      vm[nit][{get<0>(pm), get<1>(pm), get<2>(pm)+1}] += m.second;

      vm[nit][{get<0>(pm), get<1>(pm), get<2>(pm)+1}]%= p;

      //違う記号の場合
      if(get<1>(pm)+1+f(get<2>(pm)) >= n) {
        continue;
      }
      vm[nit][{get<0>(pm)+1, get<1>(pm)+1+f(get<2>(pm)), 1}] += m.second;

      vm[nit][{get<0>(pm)+1, get<1>(pm)+1+f(get<2>(pm)), 1}] %= p;
    }
    vm[it].clear();
  }

  map<ll, ll> mp;
  for(auto m: vm[(n+1)%2]){
    if(get<1>(m.first) + 1 + f(get<2>(m.first)) < n){
      mp[get<0>(m.first)] += m.second;
      mp[get<0>(m.first)] %= p;
    }
  }

  // さいごに char みて26 * 25 * 25 ... していけば
  ll ans = 0;
  for(auto m: mp){
    ans += ff(m.first) * m.second % p;
    ans %= p;
  }
  cout << ans << endl;
}
