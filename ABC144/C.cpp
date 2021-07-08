#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	ll n;
	cin >> n;
	ll t = LLINF;
	FOR(i, 1, 1000000){
		if(n % i == 0) {
			ll j = n / i;
			chmin(t, i + j - 2);
		}
	}
	cout << t << endl;
}
