#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define Graph vector<vector<int> >

using namespace std;
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	Graph G(n);
	int a, b;
	REP(i,n-1){
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

	dist[0] = 0;
  que.push(0);

	while (!que.empty()) {
		int v = que.front(); // キューから先頭頂点を取り出す
		que.pop();

		for (int nv : G[v]) {
			if (dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

	int s,t;
	REP(i,q){
		cin >> s >> t;
		if((dist[t-1] - dist[s-1]) % 2 == 0){
			cout << "Town" << endl;
		}else{
			cout << "Road" << endl;
		}
	}
}
