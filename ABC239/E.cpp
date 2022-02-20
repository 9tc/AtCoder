#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9
#define LLINF (long long)1e12
#define MOD (int)1e9+7
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

vector<priority_queue<int, vector<int>, greater<int>>> vpq;
vector<bool> seen;
VI x;

void dfs(const Graph &g, int v){
  seen[v] = true;
  vpq[v].push(x[v]);
  for(auto nextV: g[v]){
    if(seen[nextV]) continue;
    dfs(g, nextV);
    auto que = vpq[nextV];
    while(!que.empty()){
      vpq[v].push(que.top());
      que.pop();
    }
  }
  while(vpq[v].size() > 20) vpq[v].pop();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, q;
  cin >> n >> q;

  x.assign(n, 0);
  REP(i,n) cin >> x[i];
  Graph g(n);
  int u, v;
  REP(i, n-1){
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vpq.resize(n);
  seen.assign(n, false);
  dfs(g, 0);

  int vq, kq;
  REP(_, q){
    cin >> vq >> kq;
    auto que = vpq[vq-1];
    kq = que.size() - kq;
    while(kq--) {
      //cout << que.top() << " ";
      que.pop();
    }
    cout << que.top() << endl;
  }
}
