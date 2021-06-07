#include<bits/stdc++.h>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  int n;
	 cin >> n;
	 vector<ll> a(n+1,0), b(n+1,0), bt(n+1,0);
	 int t;
	 REP(i,n) {
		 cin >> t;
		 ++a[t];
	 }
	 REP(i,n){
	 	 cin >> b[i];
	 }
	 REP(i,n) {
		 cin >> t;
		 ++bt[b[t-1]];
	 }

	 ll c = 0;
	 REP(i,n+1){
		 c += a[i] * bt[i];
	 }
	 cout << c << endl;
}
