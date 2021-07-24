#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define INF (int)1e9 //10^9:∞

using namespace std;
using namespace atcoder;

int n, m;
struct edge {
    int to;
    int cost;
};

typedef pair<int, int> P;  // first: 最短距離, second: 頂点番号
int MAX_V = 250000;
int V, d[250000], cnt[250000];
vector<edge> G[250000]; // 隣接リスト表現


void dijkstra(int s) {
    fill(d, d + V, INF);
    d[s] = 0;  // 始点sへの最短距離は0
    fill(cnt, cnt + V, 0);
    cnt[s] = 1;  // 始点sへの最短経路数は1

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                cnt[e.to] = cnt[v];  // コストが更新された場合は直前の頂点への最短経路数で上書き
            } else if (d[e.to] == d[v] + e.cost) {
                cnt[e.to] += cnt[v];  // コストが一致する場合はこれまでの最短経路数を足し合わせ
								cnt[e.to] %= 1000000007;
            }
        }
    }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	cin >> n >> m;
	V = n;
	int a, b;
	REP(i,m){
		cin >> a >> b;
		edge ta = {b-1, 1};
		edge tb = {a-1, 1};
		G[a-1].push_back(ta);
		G[b-1].push_back(tb);
	}

	dijkstra(0);
	cout << cnt[n-1] << endl;
}
