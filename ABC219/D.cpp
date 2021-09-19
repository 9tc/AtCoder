#include<bits/stdc++.h>
//#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (int i = 0; (i) < ll(n); ++ (i))
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
//using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	VPII ab(n);
	REP(i,n) cin >> ab[i].F >> ab[i].S;
	vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(x+1, vector<int>(y+1, INF)));
	dp[0][0][0] = 0;
	REP(i,n){
		REP(j, x+1){
			REP(k, y+1){
				if(dp[i][j][k] == INF) continue;
				chmin(dp[i+1][j][k], dp[i][j][k]);
				chmin(dp[i+1][min(x, j + ab[i].F)][min(y, k + ab[i].S)], dp[i][j][k] + 1);
			}
		}
	}

	/*REP(i,n+1){
		REP(j,x+1){
			REP(k,y+1) cout << dp[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}
	*/

	if(dp[n][x][y] == INF) cout << -1 << endl;
	else cout << dp[n][x][y] << endl;
}
