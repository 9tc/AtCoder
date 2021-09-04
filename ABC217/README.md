# REVIEW
### A
- string s, tの辞書順比較がs < tでできること知っていれば解ける
- 文字数比較と誤読して1WA

### B
- 完全の配列と実際の配列をともにsortして比較した

### C
- vector<pair<int,int>>で入力iとそのindexをペアで貰っておいてsortして出力した
- 過去問に全く同じのあったような

### D(WA)
-　二分木実装くらいできるようになれ！！！(実装しようと後回し)
- setでできるじゃん!!!

### E(WA)
- queueにクエリ1を入れてクエリ3で一旦すべてvectorで取っておいて必要数partial_sortしてqueueに戻していた←ｱﾎ
- 戻す必要はなく別で取っておけばACだった
- vectorじゃなくてpriority_queueつかえば無駄な処理減るじゃん
