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

string solve(string x){
  string r = string(x.size(), x[1]);
  r[0] = x[0];

  int t = r[1] - r[0];
  int status = 0;
  REP(i, r.size()-1){
    if(r[i] - '0' + t > 9) {
      status = 1;
      break;
    }else if(r[i] - '0' + t < 0){
      status = -1;
      break;
    }
    r[i+1] = (char)(r[i] + t);
  }

  if(status == 0){
    if(r >= x) return r;
    else {
      ++x[1];
      x[2] = 0;
      return solve(x);
    }
  }else if(status == 1){
    ++x[0];
    x[1] = 0;
    return solve(x);
  }else{
    ++x[1];
    x[2] = 0;
    return solve(x);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string x;
  cin >> x;
  cout << solve(x) << endl;
  /*if(x.size() > 10){
    bool isDowner = true;
    REP(i,x.size()-1){
      if(x[0] < x[i+1]) isDowner = false;
    }
    if(isDowner){
      REP(i,x.size()) cout << x[0];
      cout << endl;
    }else{
      REP(i,x.size()) cout << (char)(x[0]+1);
      cout << endl;
    }
  }else if(x.size() == 10){
    if('1' < x[0] && x[0] < '9') {
      bool isDowner = true;
      REP(i,x.size()-1){
        if(x[0] < x[i+1]) isDowner = false;
      }
      if(isDowner){
        REP(i,x.size()) cout << x[0];
        cout << endl;
      }else{
        cout << solve(x) << endl;
      }
    }else if(x[0] == '1'){
      if(x > "1234567890") cout << "2222222222" << endl;
      else cout << "1234567890" << endl;
    }else{
      if(x > "9876543210") cout << "11111111111" << endl;
      else {
        cout << solve(x) << endl;
      }
    }
  }else{
    cout << solve(x) << endl;
  }
  */
}
