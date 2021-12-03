#include<bits/stdc++.h>
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

bool f(PII a, PII b){
	if(a.S == b.S) return a.F > b.F;
	else return a.S < b.S;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	ll n, d;
	cin >> n >> d;
	vector<pair<ll, ll> > w(n);
	REP(i,n) {
		cin >> w[i].F >> w[i].S;
		--w[i].F;
		--w[i].S;
	}
	sort(ALL(w), f);
	ll ans = 0;
	ll punch = -10000000000;
	REP(i, n){
		if(punch + d - 1 < w[i].F){
			++ans;
			punch = w[i].S;
		}
	}

	cout << ans << endl;
	//REP(i,n) cout << w[i].F << " " << w[i].S << endl;

	/*ll l = 1, r = 2000000000;
	while(r - l > 1){
		ll m = (l + r) / 2;
		// m回でできるか？
		//cout << m << endl;
		ll itr = 0;
		ll punch = -1;
		ll cnt = 0;
		while(itr < n){
			++cnt;
			punch = w[itr].S;
			ll li = itr, ri = n;
			while(ri - li > 1){
				ll mi = (li + ri) / 2;
				//cout << mi << endl;
				if(w[mi].F <= punch + d - 1 && w[mi].S >= punch) li = mi;
				else ri = mi;
			}
			itr = li + 1;
		}

		if(m > cnt) r = m;
		else l = m;
	}
	cout << l << endl;*/
}
