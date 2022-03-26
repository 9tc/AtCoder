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
int n, m;

VI f(VI b, VI a, VI c, int cur){
  REP(i,m+1) cerr << b[i] << " ";
  cerr << endl;

  b[cur] = c[cur + n] / a[n];

  REP(i, n+1){
    c[cur + i] -= b[cur] * a[i];
  }

  if(cur == 0) return b;
  else return f(b, a, c, cur-1);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  cin >> n >> m;
  VI a(n+1);
  REP(i,n+1) cin >> a[i];
  VI c(n+m+1);
  REP(i, n + m + 1) cin >> c[i];

  VI b(m+1, INF);
  b = f(b, a, c, m);

  REP(i,m+1) cout << b[i] << " ";
  cout << endl;
}
