#include<bits/stdc++.h>
using ll= long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  int n;
  cin >> n;
  string s, name = "t", name2 = "t";
  int t, height2 = 0, height = 0;
  REP(i,n){
    cin >> s >> t;
    if(t > height){
      name2 = name;
      name = s;
      height2 = height;
      height = t;
    }else if(t > height2){
      name2 = s;
      height2 = t;
    }
  }
  cout << name2 << endl;
}
