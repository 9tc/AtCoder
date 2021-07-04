#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define LLINF (long long)1e12

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n, m;
	cin >> n >> m;
	vector<vector<ll> > g(n, vector<ll>(n, LLINF));
	int a,b,c;
	REP(i,m){
		cin >> a >> b >> c;
		g[a-1][b-1] = c;
	}
	ll count = 0;
	REP(kt, n){
	REP(i, n){
		REP(j, n){
			//REP(k, kt+1){
				if(g[i][kt] == LLINF || g[kt][j] == LLINF) continue;
        g[i][j] = min(g[i][j], g[i][kt] + g[kt][j]);
			//}
		}
	}

	REP(i,n){
    REP(j,n){
			if(i == j) continue;
      if(g[i][j] != LLINF){
				//cout << i << " " << j << " "<< g[i][j] << endl;
				count += g[i][j];
			}
    }
  }
  }
	cout << count << endl;
}
