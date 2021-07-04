#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define ALL(x) x.begin(),x.end()

#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int> > //VVI a(n, vector<int>(m));
#define VPII vector<pair<int,int> >

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	ll n, k;
	cin >> n >> k;
	vector<pair<int,int> > a(n);
	vector<ll> b(n, k/n);
	k %= n;

	ll t;

	REP(i,n){
		cin >> t;
		a[i].first = t-1;
		a[i].second = i;
	}
	sort(ALL(a));
	REP(i, k){
		++b[a[i].second];
	}
	REP(i,n){
		cout << b[i] << endl;
	}
}
