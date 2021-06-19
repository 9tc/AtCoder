#include<bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int n;
	cin >> n;
	n *= 1.08;
	if(n < 206) cout << "Yay!" << endl;
	else if(n == 206) cout << "so-so" << endl;
	else cout << ":(" << endl;

}
