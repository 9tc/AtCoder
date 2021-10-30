#include<bits/stdc++.h>
#include <list>
#include <atcoder/all>
using ll = long long;
#define REP(i, n) for (ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for (ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for (ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FOR3R(i, m, n) for (ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9 //10^9:∞
#define LLINF (long long)1e12
#define MOD (int)1e9+7 //10^9+7:合同式の法
#define PI 3.141592653589
#define PB push_back
#define F first
#define S second

#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define Graph vector<vector<int> >
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int> > //VVI a(n, vector<int>(m));
#define VPII vector<pair<int,int> >

#define DDD fixed<<setprecision(10)

template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
T GCD(T a, T b) {
	if (b == 0)
	return a;
	else
	return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
	return (a * b) / GCD(a, b);
}

using namespace std;
using namespace atcoder;

struct Node {
    Node *next, *prev;
    int data;
};

void merge(Node* p1, Node* p2) {
  p1->next = p2;
  p2->prev = p1;
}

void separate(Node* p1, Node* p2) {
  p1->next = NULL;
  p2->prev = NULL;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Node> v(n);
    REP(i, n) {
        v[i].next = NULL;
        v[i].prev = NULL;
        v[i].data = i + 1;
    }

    REP(i, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
						x--; y--;
            merge(&v[x], &v[y]);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
						x--; y--;
            separate(&v[x], &v[y]);
        } else {
            int x;
            cin >> x;
						x--;
            Node* nd = &v[x];
            Node* nd2;
            while (true) {
                if (nd->prev == NULL) break;
                nd = nd->prev;
            }
            nd2 = nd;
            int cnt = 0;
            while (true) {
                cnt++;
                if (nd->next == NULL) break;
                nd = nd->next;
            }
            cout << cnt;
            while (true) {
                cout << " " << (nd2->data);
                if (nd2->next == NULL) break;
                nd2 = nd2->next;
            }
            cout << endl;
        }
    }
}
