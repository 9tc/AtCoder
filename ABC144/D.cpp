#include<bits/stdc++.h>
#include <atcoder/all>

#define PI 3.141592653589

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<fixed<<setprecision(10);
	double a, b, x;
	cin >> a >> b >> x;
	double xp = x / a;
	if(a * b / 2 > xp){
		double t = xp / b;
		cout << atan(b / (2 * t)) / PI * 180.0 << endl;
	}else{
		double tp = 2 * (b * a - xp) / a;
		cout << atan(tp / a) / PI * 180.0 << endl;
	}
}
