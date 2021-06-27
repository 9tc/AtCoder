#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n;
	cin >>n;
	int tmp;
	vector<pair<double, double> > t(n);
	double t1, t2;
	REP(i,n){
		cin >> tmp >> t1 >> t2;
		if(tmp == 1){
			t[i].first = t1;
			t[i].second = t2;
		}else if(tmp == 2){
			t[i].first = t1;
			t[i].second = t2 - 0.1;
		}else if(tmp == 3){
			t[i].first = t1 + 0.1;
			t[i].second = t2;
		}else{
			t[i].first = t1 + 0.1;
			t[i].second = t2 - 0.1;
		}
	}
	sort(ALL(t));

	int count = 0;
	REP(i,n-1){
		FOR(j, i+1, n-1){
			if(t[i].second < t[j].first || t[j].second < t[i].first) continue;
			else {
				++count;
			}
		}
	}

	cout << count << endl;
}
