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


ll p10(int n){
  if(n == 1) return 1;
  return 10 * p10(n-1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  ll n = stoll(s);


  ll ans = 0;
  ll r = 9;
  REP(i, s.length()-1){
    //cout << 1 << "から" << r << "のそうわ" << endl;
    if(r % 2 != 0) ans += ((r+1) / 2 % 998244353) * (r % 998244353)% 998244353;
    else  ans += ((r / 2 % 998244353) * ((r+1) % 998244353))% 998244353;
    r = r * 10;
  }

  //cout << ans << endl;

  n -= p10(s.length());
  n += 1;
  //cout << n << endl;

  if(n % 2 == 0) ans += (n / 2% 998244353) * ((n+1) % 998244353)% 998244353;
  else ans += (n % 998244353) * ((n+1)/2 % 998244353)% 998244353;

  cout << ans % 998244353  << endl;
}
