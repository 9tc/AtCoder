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
  cin >> n;
  VI a(n);
  int maxItr = 0;
  REP(i,n) {
    cin >> a[i];
    if(a[maxItr] < a[i]) maxItr = i;
  }

  VI b;
  FOR(i, maxItr+1, n-1) b.PB(a[i]);
  FOR(i, 0, maxItr-1) b.PB(a[i]);

  vector<ll> dp(n, LLINF);
  REP(i,n-1){
    if(i == 0) {
      dp[i] = b[i];
      dp[i+1] = b[i];
    }
    else dp[i+1] = min(dp[i] + b[i], dp[i-1] + b[i]);
  }

  VI bb;
  FOR(i, maxItr+2, n-1) bb.PB(a[i]);
  FOR(i, 0, maxItr) bb.PB(a[i]);

  vector<ll> dp2(n, LLINF);
  REP(i,n-1){
    if(i == 0) {
      dp2[i] = bb[i];
      dp2[i+1] = bb[i];
    }
    else dp2[i+1] = min(dp2[i] + bb[i], dp2[i-1] + bb[i]);
  }

  cout << min(dp[n-1], dp2[n-1]) << endl;
}
