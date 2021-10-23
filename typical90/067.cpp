#include<bits/stdc++.h>
#include <list>
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

string fix8to5(string s){
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '8') s[i] = '5';
	}
	return s;
}

ll base8tobase10(string n){
	ll r = 0;
	ll x = 1;
	for(int i = n.length()-1; i >= 0; --i){
		r += 1LL * (n[i] - '0') * x;
		x *= 8;
	}
	return r;
}

string base10tobase9(ll n){
	string r;
	while(n > 0){
		char c = ((n % 9) + '0');
		r = c + r;
		n /= 9;
	}
	return r;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string n;
	int k;
	cin >> n >> k;
	string s;

	if(n == "0") {
		cout << 0 << endl;
		return 0;
	}

	REP(_, k){
		n = fix8to5(base10tobase9(base8tobase10(n)));
	}
	cout << n << endl;
}
