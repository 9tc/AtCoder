#include<bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int a, b;
	cin >> a >> b;
	if(a > 9 || b > 9) cout << -1 << endl;
	else cout << a * b << endl;

}
