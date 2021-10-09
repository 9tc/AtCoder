#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
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
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> a(2 * n);
	REP(i,2 * n) cin >> a[i];
	vector<pair<int,int> > gcp(2*n);
	REP(i, 2*n) gcp[i] = make_pair(0, i);
	REP(j,m){
		int f = -1, s = -1;
		for(int i = 0; i < 2*n; i += 2){
			if(a[gcp[i].S][j] == a[gcp[i+1].S][j]){
				++gcp[i].F;
				++gcp[i+1].F;
				continue;
			}
			if(a[gcp[i].S][j] == 'G'){
				if(a[gcp[i+1].S][j] == 'P') ++gcp[i].F;
				else ++gcp[i+1].F;
			}else if(a[gcp[i].S][j] == 'C'){
				if(a[gcp[i+1].S][j] == 'P') ++gcp[i+1].F;
				else ++gcp[i].F;
			}else{
				if(a[gcp[i+1].S][j] == 'G') ++gcp[i+1].F;
				else ++gcp[i].F;
			}
		}
		sort(ALL(gcp));
	}

	REP(i,2 * n){
		cout << gcp[i].S + 1 << endl;
	}

}
