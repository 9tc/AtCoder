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
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  VVI t(n, VI(n, 0));
  REP(i,n)REP(j,n) if(s[i][j] == '#') t[i][j] = 1;

  bool isA = false;

  // yoko
  VVI lt(n+1, VI(n+1, 0));
  REP(i,n){
    REP(j,n){
      lt[i][j+1] = lt[i][j] + t[i][j];
      if(j >= 6) lt[i][j+1] -= t[i][j-6];

      if(lt[i][j+1] >= 4) {

        isA = true;
      }
    }
  }



  // tate
  VVI ut(n+1, VI(n+1, 0));
  REP(i,n){
    REP(j,n){
      ut[i+1][j] = ut[i][j] + t[i][j];
      if(i >= 6) ut[i+1][j] -= t[i-6][j];

      if(ut[i+1][j] >= 4) {

        isA = true;
      }
    }
  }



  // naname
  VVI nt(n+1, VI(n+1, 0));
  REP(i,n){
    REP(j,n){
      nt[i+1][j+1] = nt[i][j] + t[i][j];
      if(i >= 6 && j >= 6) {
        nt[i+1][j+1] -= t[i-6][j-6];

      }

      if(nt[i+1][j+1] >= 4&& i >= 5 && j >= 5) {

        isA = true;
      }
    }
  }

  REP(i,n) reverse(ALL(t[i]));
  VVI nnt(n+1, VI(n+1, 0));
  REP(i,n){
    REP(j,n){
      nnt[i+1][j+1] = nnt[i][j] + t[i][j];
      if(i >= 6 && j >= 6) nnt[i+1][j+1] -= t[i-6][j-6];

      if(nnt[i+1][j+1] >= 4 && i >= 5 && j >= 5) {
        isA = true;
      }
    }
  }


  YesNo(isA);
}
