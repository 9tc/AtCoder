# REVIEW
### A
- むずくない？？
- つける時間と消す時間の前後を分類して判定

### B
- 制約が狭いのでシミュレート

### C
- むずい！
- 2分探索で次300点とってほかの人0点の時にk番目に入り込めるか見る
- 4回目のテストでの可能性って部分につまづいてた

### D(WA)
- auto find = [&](auto&& self, int x) -> int{
		if(u[x] == x) return x;
		else return u[x] = self(self, u[x]);
	};
  みたいな書き方をようやく学んだ
- 理屈がまだ理解できてないような
- UnionFindっぽいってことはわかった
