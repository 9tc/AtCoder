#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9 //10^9:∞
#define LLINF (long long)(1LL<<62)-1
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

struct UnionFind{
	vector<int> par, siz;

	UnionFind(int n) : par(n, -1), siz(n,1) {}

	int root(int x){
		if(par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y){
		return root(x) == root(y);
	}

	bool unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if(siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
 	}

	int size(int x){
		return siz[root(x)];
	}
};

int main() {
	int n = 1048576;
	int q;
	cin >> q;

	ll t, x, h;
	vector<ll> v(n, -1);
	vector<ll> u(n+1, 0);
	REP(i, n) u[i] = i;

	auto find = [&](auto&& self, int x) -> int{
		if(u[x] == x) return x;
		else return u[x] = self(self, u[x]);
	};

	REP(_, q){
		cin >> t >> x;

		if(t == 1){
			int i = find(find, x % n);
			v[i] = x;
			u[i] = find(find, i+1);
		}else{
			cout << v[x % n] << endl;
		}
	}
}
