#include<bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	if(n > a) cout << a * x + (n-a) * y << endl;
	else cout << n * x << endl;
}
