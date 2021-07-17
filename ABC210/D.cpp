
#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define ALL(x) x.begin(),x.end()

#define LLINF (long long)1e12

template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
using namespace atcoder;

int main() {
	ll h, w, c;
	cin >> h >> w >> c;
	vector<vector<ll> > a(h, vector<ll>(w, 0));
	REP(i,h) REP(j,w) cin >> a[i][j];
	ll ans = LLINF;
	REP(z, 2){
		vector<vector<ll> > dp(h+1, vector<ll>(w+1, LLINF));
		REP(i, h){
			REP(j, w){
				dp[i+1][j+1] = min(a[i][j], min(dp[i][j+1] + c, dp[i+1][j] + c));
			}
		}

		REP(i, h){
			REP(j, w){
				chmin(ans, min(dp[i][j+1], dp[i+1][j]) + c + a[i][j]);
			}
		}
		reverse(ALL(a));
	}
	cout << ans << endl;
}
