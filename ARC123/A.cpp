
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


int main() {
	vector<ll> a(3, 0);
	cin >> a[0] >> a[1] >> a[2];
	ll ans = 0;
	vector<ll> t(3, a[1]);
	t[0] = min(a[0], a[2]);
	t[2] = max(a[0], a[2]);
	if(t[1] <= t[0]){
		ans += (t[2] + t[0])/2 - t[1];
		t[1] = (t[2] + t[0])/2;
	}
	//t[0] <=(b1)= t[1] <=(b2)= t[2]
	ll b1 = t[1] - t[0];
	ll b2 = t[2] - t[1];
	ll k = b2 - b1;
	if(k < 0){
		ans += b1 - b2;
	}else if(k > 0){
		ans += k/2;
		b2 -= k/2;
		b1 += k/2;
		if(b2 - b1 > 0) ans += 2;
	}
	cout << ans << endl;
}
