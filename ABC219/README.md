# REVIEW
### A
- 一瞬
- if elseif elseの使い方

### B
- 一瞬
- char - '1'でsのindex

### C
- sortの比較器を作る
- Xを元に1文字ずつ比較させる

### D
- 3次元DP
- dp[i+1][j][k] = dp[i][j][k]でchmin使ってなかったので5WA (気づかなかった)

### E(WA)
- フロンティア法！？と思ったけどbit全探索？
- 領域が単一であることの判定が難しそう？
  - grid全体を+-1したと考えて6x6マスで2つの領域に分けられることが示せればよい？

### F(WA)
- フロンティア法？実装ﾑﾘ！となったのでこちらを考えてた
- 1回で通るマスの総数 * k から 2回連続で行ったとき重複して通るマスの数 * (k-1)　すればよさそうと思ってた