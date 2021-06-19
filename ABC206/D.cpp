#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define VI vector<int>

template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}


using namespace std;
using namespace atcoder;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k){
		int r = -data[find(k)];
		data[find(k)] = -1;
    return(r);
  }
};


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n;
	cin >> n;
	VI a(n);
	int maxt = 0;
	REP(i,n) {
		cin  >> a[i];
		chmax(maxt, a[i]);
	}
	UnionFind uf(maxt+1);
	REP(i, n/2){
		uf.unite(min(a[i], a[n-i-1]), max(a[i], a[n-i-1]));
	}

	ll count = 0;
	REP(i, n){
		count += uf.size(a[i])-1;
	}
	cout << count << endl;
}
