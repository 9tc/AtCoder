#include<bits/stdc++.h>
#include <atcoder/all>

#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

using namespace std;
using namespace atcoder;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //cout<<fixed<<setprecision(10);
	int a, b;
	cin >> a >> b;
	YesNo(a <= b && a * 6 >= b );
}
