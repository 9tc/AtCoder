#include<bits/stdc++.h>
using ll= long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)

using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  VI a(10), b;
  char c;
  REP(i,10){
    cin >> c;
    if(c == 'o'){
      a[i] = 1;
      b.push_back(i);
    }
    else if(c == 'x') a[i] = -1;
    else a[i] = 0;
  }
  int count = 0;
  REP(i, 10){
    if(a[i] == -1) continue;
    REP(j, 10){
      if(a[j] == -1) continue;
      REP(k, 10){
        if(a[k] == -1) continue;
        REP(l, 10){
          if(a[l] == -1) continue;
          bool hasAllB = true;
          for(auto t: b){
            if(t == i || t == j || t == k || t == l) continue;
            else {
              hasAllB = false;
              break;
            }
          }
          if(hasAllB){
            ++count;
          }
        }
      }
    }
  }
  cout << count << endl;
}
