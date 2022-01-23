#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9 //10^9:∞
#define LLINF (long long)1e12
#define MOD (int)1e9+7 //10^9+7:合同式の法
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
  int n;
  vector<vector<ll> > t;

ll f(vector<int> a, int cnt){
  if(cnt == 2*n){
    // 排他的論理和


    ll ans = t[a[0]][a[1]];
    for(int i = 2; i < 2*n; i += 2){
      ans ^= t[a[i]][a[i+1]];
    }
    return ans;
  }

  ll ans = 0;
  for(int i = cnt+1; i < n*2; ++i){
    VI b = a;
    //cout << cnt+1 << " " << i << endl;
    b[cnt+1] = a[i];
    b[i] = a[cnt+1];
    chmax(ans, f(b, cnt+2));
  }
  return ans;
}

int main(){

  cin >> n;
  t.assign(2*n, vector<ll>(2*n, 0));
  ll tmp;
  REP(i,2*n){
    FOR(j, i+1, 2*n-1){
      cin >> tmp;
      t[i][j] = tmp;
      t[j][i] = tmp;
    }
  }

  vector<int> b(2*n);
  REP(i,2*n) b[i] = i;

  cout << f(b, 0) << endl;

}
