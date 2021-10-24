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

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	VVI g(n);
	int u, v;
	VI inedge(n, 0);
	REP(i,m){
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		++inedge[v];
	}

	priority_queue<int, vector<int>, greater<int> > que;
	REP(i,n) if(inedge[i] == 0) que.push(i);

	VI ans;

	while(!que.empty()){
		int i = que.top(); que.pop();

		ans.PB(i);
		for(int j: g[i]){
			--inedge[j];
			if(inedge[j] == 0) que.push(j);
		}
	}

	if(ans.size() != n) cout << -1 << endl;
	else {
		REP(i,n) cout << ans[i]+1 << " ";
		cout << endl;
	}
}
