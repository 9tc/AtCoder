#include<bits/stdc++.h>
//#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (int i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9 //10^9:∞
#define LLINF (long long)1e12
#define MOD (int)1e9+7 //10^9+7:合同式の法
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
//using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	string s;
	cin >> s;
	ll k;
	cin >> k;
	ll pc = 0;
	VPII po;
	int x = 0, y = 0;
	for(char c: s){
		po.push_back(make_pair(x, y));
		if(c == 'L') --x;
		else if(c == 'R') ++x;
		else if(c == 'U') ++y;
		else --y;
	}
	po.push_back(make_pair(x, y));
	sort(ALL(po));
	po.erase(unique(po.begin(), po.end()), po.end());
	pc = 1LL * po.size();
	ll kas = 0;
	for(int i = 0; i < po.size()-1; ++i){
		for(int j = i+1; j < po.size(); ++j){
			if(po[i].first == po[j].first + x && po[i].second == po[j].second + y){
				++kas;
			}
		}
	}
	cout << pc << endl;
	cout << pc * k - kas * (k-1) << endl;
}
