#include<bits/stdc++.h>
using ll = long long;

using namespace std;

ll dp[31][31];

ll ka(int i,int j){
	if(i < j+1) return 1;
	else return i * ka(i-1, j);
}

string f(int a, int b, ll k){
	if(a == 0 && b == 0) return "";
	if(a == 0) return "b" + f(a, b-1, k);
	if(b == 0) return "a" + f(a-1, b, k);
	ll t = dp[a-1][b];

	if(t >= k) return "a" + f(a-1, b, k);
	else return "b" + f(a, b-1, k - t);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
	int a, b;
	ll k;
	cin >> a >> b >> k;
	dp[0][0] = 1;
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
				if (i > 0) {
						dp[i][j] += dp[i - 1][j];
				}
				if (j > 0) {
						dp[i][j] += dp[i][j - 1];
				}
		}
	}

	cout << f(a, b, k) << endl;
}
