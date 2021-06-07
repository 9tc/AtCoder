#include<bits/stdc++.h>
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
using namespace std;


signed main() {
	ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n,k;
	cin >> n >> k;
	int sum = 0;
	FOR(i, 1, n){
		FOR(j, 1, k){
			sum += i * 100 + j;
		}
	}
	cout << sum << endl;
}
