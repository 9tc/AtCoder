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


void printAns(VI ans, int i){
  if(i % 2 == 1) reverse(ALL(ans));
  REP(i, ans.size()){
    if(i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  VI s(n);
  REP(i,n) cin >> s[i];

  vector<ll> x(n+2, 0);
  REP(i, n) x[i+2] = s[i] - x[i] - x[i+1];

  vector<ll> c(3,  LLINF);
  REP(i,n+2) chmin(c[i % 3], x[i]);

  c[0] *= -1;
  c[1] *= -1;

  if(c[0] + c[1] > c[2]){
    cout << "No" << endl;
    return 0;
  }

  c[2] = - c[0] - c[1];

  REP(i, n+2) x[i] += c[i % 3];

  cout << "Yes" << endl;
  REP(i,n+2){
    if(i != 0) cout << " ";
    cout << x[i];
  }
  cout << endl;
}
