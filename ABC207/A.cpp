#include<bits/stdc++.h>
#include <atcoder/all>


using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(a+b, max(b+c, c+a )) << endl;
}
