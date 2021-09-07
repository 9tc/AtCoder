#include<bits/stdc++.h>
using ll= long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
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

#define Graph vector<vector<int>>
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>> //VVI a(n, vector<int>(m));
#define VPII vector<pair<int,int>>

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

string f(int i){
	return i == 1 ? "+" : "-";
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);

	int n, m;
	cin >> n >> m;
	VI k(m);
	VVI s(n); //スイッチs[i]に繋がっている電球
	int t;
	REP(i,m){
		cin >> k[i];
		REP(j,k[i]) {
			cin >> t;
			s[t-1].push_back(i);
		}
	}
	VI p(m);
	REP(i,m) cin >> p[i];

	int ans = 0;
	for(int b = 0; b < (1<<n); ++b){
		VI tp(m, 0);
		REP(i,n){
			if(b & (1<<i)){ //スイッチs[i]
				for(auto den: s[i]){
					++tp[den];
				}
			}
		}

		//REP(i,m) cout << tp[i] << " ";
		//cout << endl;

		bool cnt = true;
		REP(i,m){
			if(tp[i] % 2 != p[i]){
				cnt = false;
				break;
			}
		}
		if(cnt) ++ans;
	}
	cout << ans << endl;
}
