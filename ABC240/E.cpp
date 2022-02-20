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

VPII ans;

vector<bool> seen;
int bg; // 区間の良い感じの数を格納

void dfs(const Graph &g, int v){
  seen[v] = true;
  int cnt = 0;
  int minBg = INF, maxBg = 0;

  for(auto nextV: g[v]){
    if(seen[nextV]) continue;
    ++cnt;
    dfs(g, nextV);
    if(ans[nextV].F != -1) chmin(minBg, ans[nextV].F);
    if(ans[nextV].S != -1) chmax(maxBg, ans[nextV].S);
  }
  if(cnt == 0){
    ans[v] = {bg, bg};
    ++bg;
  }else{
    ans[v] = {minBg, maxBg};
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
  cin >> n;
  Graph g(n);
  REP(i,n-1){
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].PB(v);
    g[v].PB(u);
  }
  bg = 1;
  ans.resize(n);
  seen.assign(n, false);

  dfs(g, 0);

  REP(i,n){
    cout << ans[i].F << " " << ans[i].S << endl;
  }
}
