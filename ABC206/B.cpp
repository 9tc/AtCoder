#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n;
	cin >> n;
	REP(i,n+1){
		if(f(i) >= n){
			cout << i << endl;
			break;
		}
	}
}
