#include<bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))

using namespace std;
using namespace atcoder;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int t;
	REP(i,n){
		if(s[i] == '1'){
			t = i;
			break;
		}
	}
	if(t % 2 == 1) cout << "Aoki" << endl;
	else cout << "Takahashi" << endl;
}
