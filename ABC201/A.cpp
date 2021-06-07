#include<bits/stdc++.h>
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  YesNo(a1 + a2 == 2 * a3 || a1 + a3 == 2 * a2 || a2 + a3 == 2 * a1);
}
