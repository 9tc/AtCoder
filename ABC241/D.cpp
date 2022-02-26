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

	int q;
  cin >> q;

  multiset<ll> st;
  while(q--){
    int c;
    cin >> c;
    if(c == 1){
      ll x;
      cin >> x;
      st.insert(x);
    }else{
      ll x, k;
      cin >> x >> k;
      if(c == 2){
        auto t = st.upper_bound(x);
        bool isAns = true;
        REP(i,k) if(prev(t,i) == st.begin()){
          isAns = false;
          break;
        }

        if(isAns) cout << *prev(t, k) << endl;
        else cout << -1 << endl;
      }else{
        auto t = st.lower_bound(x);
        bool isAns = true;
        REP(i,k) if(next(t,i) == st.end()){
          isAns = false;
          break;
        }

        if(isAns) cout << *next(t, k-1) << endl;
        else cout << -1 << endl;
      }
    }
  }
}
