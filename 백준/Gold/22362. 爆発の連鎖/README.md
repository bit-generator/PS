# [Gold V] 爆発の連鎖 - 22362 

[문제 링크](https://www.acmicpc.net/problem/22362) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 3월 18일 01:49:37

### 문제 설명

<p>あなたは爆弾を使ったゲームで遊んでいる．このゲームのフィールドは幅 <i>W</i> マス，高さ <i>H</i> マスのマス目状である．このフィールドの左から <i>x</i> 列目，上から <i>y</i> 行目のマスは <i>(x, y)</i> と表される．</p>

<p>このフィールド上に <i>N</i> 個の爆弾が配置されており，<i>i</i> 番目の爆弾の位置は <i>(x<sub>i</sub>, y<sub>i</sub>)</i> である．このゲームの爆弾は，爆発したとき爆弾のあるマスから上下左右それぞれの方向 <i>D</i> マス以内の十字型の領域内にある爆弾を誘爆して消失する．また，爆弾は別の爆弾によって誘爆されたときにも連鎖して爆発する．この爆発は他に爆発する爆弾が無くなるまで続く．</p>

<p>このゲームの攻略には，ある爆弾を爆発させたときに合計で何個の爆弾が爆発するか知ることが重要である．あなたは攻略を有利に進めるためのプログラムを作ることにした．</p>

<p>例として，入力サンプルの最後のデータセットは以下の図のようになる．このデータセットでは <i>(4, 1)</i> の位置にある 4 番目の爆弾が最初に爆発する．その後，以下のように爆発が連鎖する．</p>

<ul>
	<li><i>(4, 1)</i> の位置の爆弾から上下左右それぞれの方向 3 マス以内にある爆弾を誘爆する．</li>
	<li><i>(5, 1)</i> と <i>(4, 4)</i> の位置の爆弾が誘爆により連鎖して爆発し，各々の上下左右それぞれの方向 3 マス以内にある爆弾を誘爆する．</li>
	<li><i>(3, 4)</i> と <i>(1, 4)</i> の位置の爆弾が誘爆により連鎖して爆発する．このとき新しく誘爆される爆弾はない．</li>
</ul>

<p>よって <i>(4, 1)</i> の位置にある爆弾が爆発すると合計で 5 つの爆弾が爆発する．</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/747629b7-112b-47c0-87f9-e7753774dd08/-/preview/" style="width: 272px; height: 200px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/17dca2f6-9455-463a-a08e-4ec193a004b4/-/preview/" style="width: 278px; height: 200px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/90615b89-f702-4bcb-bf05-ed846922763c/-/preview/" style="width: 278px; height: 200px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4d8a64e7-0851-47af-be2e-3210d1f0acde/-/preview/" style="width: 278px; height: 200px;"></p>

### 입력 

 <p>入力は最大で 50 個のデータセットからなる．各データセットは次の形式で表される．</p>

<pre><i>W</i> <i>H</i> <i>N</i> <i>D</i> <i>B</i>
<i>x<sub>1</sub></i> <i>y<sub>1</sub></i>
<i>x<sub>2</sub></i> <i>y<sub>2</sub></i>
<i>...</i>
<i>x<sub>N</sub></i> <i>y<sub>N</sub></i></pre>

<p>各データセットは <i>N+1</i> 行からなる．</p>

<p>1 行目はフィールドの幅 <i>W</i> (<i>1 ≤ W ≤ 100</i>)，高さ <i>H</i> (<i>1 ≤ H ≤ 100</i>)，爆弾の数 <i>N</i> (<i>1 ≤ N ≤ min(100, WH)</i>)，爆弾の爆発の大きさ <i>D</i> (<i>1 ≤ D ≤ 100</i>)，最初に爆発する爆弾の番号 <i>B</i> (<i>1 ≤ B ≤ N</i>) を表す整数である．</p>

<p>2 行目から続く <i>N</i> 行はそれぞれ <i>N</i> 個の爆弾の位置を表す．<i>i + 1</i> 行目は <i>i</i> 番目の爆弾の位置 <i>(x<sub>i</sub>, y<sub>i</sub>)</i> を表す整数であり <i>1 ≤ x<sub>i</sub> ≤ W</i>，<i>1 ≤ y<sub>i</sub> ≤ H</i> を満たす．各データセットについて同じマスに複数の爆弾が配置されることはない．</p>

<p>入力の終わりは 5 つのゼロからなる行で表される．</p>

### 출력 

 <p>各データセットについて，最初に <i>B</i> 番目の爆弾が爆発したときに，最終的に爆発する爆弾の数を 1 行で出力せよ．</p>

