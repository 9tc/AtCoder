#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define VI vector<int>
#define VVI vector<vector<int> >
using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	string s;
	cin >> s;
	VVI choku(8);
	vector<vector<modint1000000007> > dp(9, vector<modint1000000007>(s.length()+1, 0));
	dp[0][0] = 1;
	REP(i, s.length()){
		char c = s[i];
		REP(k,9){
			dp[k][i+1] = dp[k][i];
		}
		switch(c){
			case 'c':
				dp[1][i+1] += dp[0][i] ;
				break;
			case 'h':
				dp[2][i+1] += dp[1][i];
				break;
			case 'o':
				dp[3][i+1] += dp[2][i];
				break;
			case 'k':
				dp[4][i+1] += dp[3][i];
				break;
			case 'u':
				dp[5][i+1] += dp[4][i];
				break;
			case 'd':
				dp[6][i+1] += dp[5][i];
				break;
			case 'a':
				dp[7][i+1] += dp[6][i];
				break;
			case 'i':
				dp[8][i+1] += dp[7][i];
				break;
		}
	}
	cout << dp[8][s.length()].val() << endl;
}
