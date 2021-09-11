#include <bits/stdc++.h>
//#include <atcoder/all>
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
	int n;
VVI rotate(VVI s){
	VVI r(n, vector<int>(n));
	REP(i,n)REP(j,n){
		r[i][j] = s[n - j - 1][i];
	}
	return r;
}

VVI slide(VVI s, int dx, int dy){
	VVI r(n, vector<int>(n));
	REP(i,n)REP(j,n){
		if(i+dx < 0 ||  i + dx >= n || j + dy < 0 || j + dy >= n) r[i][j] = 0;
		else r[i][j] = s[i+dx][j+dy];
	}
	return r;
}

void printV(VVI a){
	REP(i,n){
		REP(j,n)cout << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool eq(VVI a, VVI b){
	//printV(a);
	//printV(b);
	REP(i,n){
		REP(j,n){
			if(a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	cin >> n;
	VVI s(n, vector<int>(n));
	VVI t(n, vector<int>(n));

	list<pair<int,int> > l;
	char c;
	int ss = 0, tt = 0;
	REP(i,n){
		REP(j,n){
			cin >> c;
			if(c == '#'){
				s[i][j] = 1;
				l.push_back(make_pair(i, j));
			} else s[i][j] = 0;
			ss += s[i][j];

		}
	}
	REP(i,n){
		REP(j,n){
			cin >> c;
			if(c == '#') t[i][j] = 1;
			else t[i][j] = 0;
			tt += t[i][j];
		}
	}

	if(ss != tt) {
		cout << "No" << endl;
		return 0;
	}

	REP(i,4){
		//s = rotate(s);
		FOR(j, -n+1, n-1) {
			FOR(k, -n+1, n-1){
				bool flag = true;
				for(auto h: l){
					if(h.first + j < 0 || h.first + j >= n || h.second + k < 0 || h.second + k >= n || !t[h.first + j][h.second + k]){
						flag = false;
						break;
					}
				}
				if(flag){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
		list<pair<int,int> > nl;
		for(auto h: l) nl.push_back(make_pair(h.second, n-1-h.first));
		l = nl;
	}
	cout << "No" << endl;
}
