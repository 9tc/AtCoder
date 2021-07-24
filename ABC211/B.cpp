#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

#define ALL(x) x.begin(),x.end()

#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}


using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	vector<string>s(4);
	REP(i,4) cin >> s[i];

	sort(ALL(s));
	YesNo(s[0] == "2B" && s[1] == "3B" && s[2] == "H" && s[3] == "HR");
}
