#include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	cout << max(0, b - a + 1) << endl;
}
