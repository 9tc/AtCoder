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


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	deque<int> que;
	vector<deque<int> > a(m);
	vector<vector<ll> > mem(n);

	REP(i,m){
		int k;
		cin >> k;
		REP(j,k){
			int t;
			cin >> t;
			a[i].push_back(t-1);
		}
		mem[a[i].front()].push_back(i);
	}



	REP(i,n){
		if(mem[i].size() == 2) que.push_back(i);
	}

	while(!que.empty()){
		int now = que.front(); que.pop_front();
		for(auto p: mem[now]){
			a[p].pop_front();
			if(!a[p].empty()){
				mem[a[p].front()].push_back(p);
				if(mem[a[p].front()].size() == 2) que.push_back(a[p].front());
			}
		}
	}


	for(auto p: a){
		if(!p.empty()) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
