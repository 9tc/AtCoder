#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define ALL(x) x.begin(),x.end()


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

int main() {
	int n, k;
	cin >> n >> k;
	VI c(n);
	int max = 0;
	VI vals;
	REP(i,n) {
		cin >> c[i];
		vals.push_back(c[i]);
	}
	sort(ALL(vals));
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; ++i) {
 		c[i] = lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin();
		chmax(max, c[i]);
	}
	int tmp = 0;
	int ans = 0;
	unordered_set<int> s;
	VI counter(max+1, 0);
	REP(i,n){
		s.insert(c[i]);
		++counter[c[i]];
		if(i >= k){
			if(counter[c[i-k]] == 1) s.erase(c[i-k]);
			--counter[c[i-k]];
		}
		chmax(ans, (int)s.size());
	}
	cout << ans << endl;
}
