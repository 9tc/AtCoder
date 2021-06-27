#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
 ll a, b, c, d;
	cin >> a >> b >> c >> d;
	bool can = false;
	int n = 0;
	while(n <= 100000){
		if(a + n * b <= n * c * d){
			can = true;
			break;
		}
		++n;
	}
	if(can) cout << n << endl;
	else cout << -1 << endl;
}
