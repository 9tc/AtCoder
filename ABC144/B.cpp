#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))

#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}


using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n;
	cin >> n;
	bool t = false;
	FOR(i, 1, 9){
		if(n % i == 0 && n / i < 10) {
			t = true;
		}
	}
	YesNo(t);
}
