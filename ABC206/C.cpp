#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

using namespace std;
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	ll n;
	cin >> n;
	VI a(n);
	REP(i,n) cin >> a[i];
	sort(ALL(a));
	vector<ll> b(n, 0);
	int t = 1;
	int pt = 0;
	REP(i,n){
		if(t == a[i]) ++b[pt];
		else{
			t = a[i];
			++pt;
			++b[pt];
		}
	}
	ll sum = n * (n-1) / 2;
	REP(i, pt+1){
		sum -= b[i]*(b[i]-1) / 2;
	}
	cout << sum << endl;
}
