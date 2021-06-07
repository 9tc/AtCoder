#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
  cin.tie(nullptr);

	int a,b,c;
	cin >> a >> b >> c;
	if(a == b) cout << c << endl;
	else if(b == c) cout << a << endl;
	else if(c == a) cout << b << endl;
	else cout << 0 << endl;
}
