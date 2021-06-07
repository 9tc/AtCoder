#include<bits/stdc++.h>
using ll = long long;
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  string s;
	cin >> s;
	REPR(i, s.length()){
		char c = s[i];
		if(c == '9') cout << '6';
		else if(c == '6') cout << '9';
		else cout << c;
	}
	cout << endl;
}
