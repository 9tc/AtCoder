#include<bits/stdc++.h>
using ll= long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define VVI vector<vector<int>> //VVI a(n, vector<int>(m));

using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  int h, w;
  cin >> h >> w;
  VVI a(h+1, vector<int>(w+1, 0));
  char tc;
  REP(i, h) REP(j, w){
    cin >> tc;
    if(tc == '-')  a[i][j] = -1;
    else a[i][j] = 1;
  }

  VVI o(h+1, vector<int>(w+1, 0));

  for (int i = h - 2; i != -1; --i) {
		o[i][w-1] = a[i+1][w-1] - o[i+1][w-1];
	}
	for (int j = w - 2; j != -1; --j) {
		o[h-1][j] = a[h-1][j+1] - o[h-1][j+1];
	}

	for (int i = h - 2; i != -1; --i) {
		for (int j = w - 2; j != -1; --j) {
			o[i][j] = max(a[i + 1][j] - o[i + 1][j], a[i][j + 1] - o[i][j + 1]);
		}
	}

  int t = o[0][0];
  if(t < 0) cout << "Aoki" << endl;
  else if(t > 0) cout << "Takahashi" << endl;
  else cout << "Draw" << endl;
}
