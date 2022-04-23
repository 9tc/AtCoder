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
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;

  bool tSl = false, aSl = false;
  int tt = a, ta = d;
  int lt = 0, la = 0;

  REP(i,x){
    if(!tSl) lt += b;
    if(!aSl) la += e;

    --tt;
    --ta;
    if(tt == 0){
      if(tSl){
        tSl = false;
        tt = a;
      }else{
        tSl = true;
        tt = c;
      }
    }

    if(ta == 0){
      if(aSl){
        aSl = false;
        ta = d;
      }else{
        aSl = true;
        ta = f;
      }
    }
  }

  if(lt > la) cout << "Takahashi" << endl;
  else if(lt == la) cout << "Draw" << endl;
  else cout << "Aoki"<< endl;
}
