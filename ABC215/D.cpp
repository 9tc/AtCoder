#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
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
using namespace atcoder;

set<ll> factors;
void f(ll n) {
	for (ll i = 2; i*i <= n; ++i) {
		if (n % i != 0) continue;
		ll t = 0;
		while (n % i == 0) {
			++t;
			n /= i;
		}
		factors.emplace(i);
	}
	if (n != 1) factors.emplace(n);
 }


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	VI a(n);
	REP(i,n) cin >> a[i];
	REP(i,n) f(a[i]);

	vector<bool> b(m, true);

	for(auto i: factors){
		if(i != 1) for(int j = i; j <= m; j += i) b[j-1] = false;
	}

	VI ans;
	REP(i, b.size()){
		if(b[i]) ans.push_back(i+1);
	}

	cout << ans.size() << endl;
	REP(i,ans.size()) cout << ans[i] << endl;
}