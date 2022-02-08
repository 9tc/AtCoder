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

// sから最も遠い頂点とその長さのペアを返す
PII BFS_l(int n, Graph &G, int s){
  VI dist(n, INF);
  queue<int> Q;
  Q.push(s);
  dist[s] = 0;

  while(!Q.empty()){
    int pos = Q.front(); Q.pop();
    for(int to: G[pos]){
      if(dist[to] == INF){
        dist[to] = dist[pos] + 1;
        Q.push(to);
      }
    }
  }

  int maxDist = -1, maxDistVertex = -1;
  REP(i,n){
    if(maxDist < dist[i]){
      maxDist = dist[i];
      maxDistVertex = i;
    }
  }

  return {maxDistVertex, maxDist};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n;
  cin >> n;

  Graph G(n);
  int u, v;
  REP(i,n-1){
    cin >> u >> v;
    --u, --v;
    G[u].PB(v);
    G[v].PB(u);
  }

  auto maxDist = BFS_l(n, G, 0);
  maxDist = BFS_l(n, G, maxDist.F);

  cout << maxDist.S + 1 << endl;
}
