#include<bits/stdc++.h>
using ll = long long;

using namespace std;


signed main() {
	ios::sync_with_stdio(false);
  cin.tie(nullptr);

	ll n,k;
	cin >> n >> k;
	ll position = 0;
	vector<pair<ll, int> > ab(n);
	REP(i,n) cin >> ab[i].first >> ab[i].second;
	sort(ab.begin(), ab.end());
	int pointer = 0;
	while(k != -1){
		if(k - (ab[pointer].first - position) < 0 || pointer >= n){
			position += k;
			break;
		}
		if(position < ab[pointer].first){
			k -= ab[pointer].first - position;
			position = ab[pointer].first;
		}else{
			k += ab[pointer].second;
			++pointer;
		}
	}
	cout << position << endl;
}
