#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define ALL(x) x.begin(),x.end()

using namespace std;
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
	cin >> n;
	VI c(n);
	modint1000000007 sum = 0;
	REP(i,n) cin >> c[i];

	sort(ALL(c));
	REP(i,n) sum *= c[i] -  i;

	cout << sum.val() << endl;
}
