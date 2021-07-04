#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))

#define VI vector<int>
using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int p;
	cin >> p;

	int pp = max((int)sqrt(p), 4);

	VI y = vector<int>(pp+1, 1);
	int point;
	FOR(i, 1, pp) {
		y[i] = y[i-1] * i;
		if(y[i] > p){
			point = i;
			break;
		}
	}

	int count = 0;
	REPR(i, point){
		if(p >= y[i]){
			count += p / y[i];
			p = p % y[i];
			if(p == 0) break;
		}
	}
	cout << count << endl;
}
