#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

using namespace std;
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	ll n, x;
	cin >> n >> x;
	ll t;
	REP(i,n){
		cin >> t;
		if(i % 2 == 1) t -= 1;
		x -= t;
	}
	YesNo(x >= 0);
}
