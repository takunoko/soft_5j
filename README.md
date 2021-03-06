# 夏休み双六

## ルール
- 夏休みの日々をマスとしたすごろくである
- プレイヤーはそれぞれ2種類のステータス(**充実ポイント/課題ポイント**)を持っている。
- プレイヤーはサイコロを振り出た目の数に応じて移動し、止まったマスの内容の挙動を行う。
- 最終的に **課題ポイントを0** にし **充実ポイントが多い** プレイヤーの勝利となる。
	- 最後のマスに到達した時点で課題ポイントが残っている場合は負けとなる
- すべてのプレイヤーが1度行動をする度にイベントが発生する。
	- プレイヤーはイベントに参加、不参加を選択することができる。
		- 不参加を選択した場合は一定の課題ポイントを減少させる。
		- 参加を選択した場合は基本的に充実ポイントが増加するイベントが発生する。
	- イベントは基本的にサイコロを用いて各プレイヤーのステータスを変化させる。


## 物の抽出
### プレイヤー
各プレイヤーは2種類のステータス(**充実ポイント/課題ポイント**)とプレイヤー名を持つ。
(例)

```Player1
(名前):ああああ
充実ポイント: 200pt
課題ポイント: 1500pt
```
### マス
各マス(40マス程度)にはそれぞれその日のイベントとステータスの変化量が存在する。
(例)

```7/18日
夏休み初日。初日ということであまり行動しなかった。だらだらして1日を終える。
充実ポイント: 10増 / 課題ポイント: 1減
```
### イベント
イベントは参加したプレイヤーに対してサイコロなどを用いてステータスを変化させる。
(例)

```海イベント
サイコロを振ってでた目の数*10の充実ポイントをゲット!!
```

## ふるまい
### プレイヤー
プレイヤーはサイコロを振ることによって移動し、移動したマスのイベントを実行する。

### マス
各マスに充実ポイント、課題ポイントの増減が決められている。マスに止まったプレイヤーに対してステータスを変化させる

### イベント
参加したプレイヤーに対して、サイコロなどを用いてステータス増減量を決定する。
イベントごとに増減量や増減方法が異なる。どのイベントが発生するかはランダムで決定する。

## データ構造(図)
### PLAYER
	player_list[10];  // プレイヤーの最大数分宣言する
	├── name[20];  // 20文字以内でプレイヤー名を保持する
	├── int position;  // プレイヤーの現在地を示す
	├── int K_pt;  // 課題ポイント
	├── int J_pt;  // 充実ポイント
	└── int flg;  // 汎用フラグ


### DAY_EVENT
	day_list[50]  // 日付の数だけ用意
	├── char content[200];  // イベントの概要の説明。
	├── int K_pt;  // 課題ポイントの増減(-10など)
	└── int J_pt;  // 充実ポイントの増減(+20など)

## 関数仕様
```yes_no
引数 : void
戻り値: (1/0)
内容 : 「はい(y) / いいえ(n)」で間違いがないように促すさいに利用する。
はいの場合に1が返され、いいえの場合に0が返される。
```

```disp_plyaer_status
引数 : PLAYER *player
戻り値: void
内容 : プレイヤーのステータスを表示する
```

```init_program
引数 : int tmp
戻り値: void
内容 : プログラムの初期化を行う
```

```load_day_event_data
引数 : DAY_EVENT day_event[], char *file_name
戻り値: int
内容 : 外部ファイル(csv)から各日付のデータを読み込む。
戻り値は読み込んだ日付の数
```

```throw_dice
引数 : int max_num
戻り値: int
内容 : 擬似乱数を用いて1~max_numの範囲で乱数を生成する。
戻り値として生成した乱数を返す
```

``` init_game
引数 : PLAYER *player_list
戻り値: int
内容 : プレイヤー数を決定して、プレイヤー数に応じてプレイヤー配列を初期化する。
戻り値はプレイヤー数
```

```move_player
引数 : DAY_EVENT day_list[], PLAYER *player
戻り値: void
内容 : プレイヤーをサイコロを用いて移動させる。
止まったマスに対するイベント内容を表示し、プレイヤーのステータスを変化させる。
```

```select_event_player
引数 : PLAYER player_list[], int p_size, int *p_list
戻り値: void
内容 : イベントに参加するプレイヤーを決定する。引数に与えられた配列に参加するプレイヤーの番号を格納する。
```

### イベント関数
```e_sea
引数 : PLAYER player_list[], int p_num[]
戻り値: void
内容 : サイコロなどを用いたイベントを行い、プレイヤーのステータスを変化させる。
```
上記の様な関数をイベントの数だけ生成する。

## コード化
### データ構造
別紙 data_set.h
### 関数
別紙 event.c, main.c, tools.c

## 実行結果
ファイルからマスの読み込みと3人のプレイヤーを生成して、1回ずつ行動した。
また、イベントを1度実行してステータスを変化させた際の実行結果である。

```main
-----aaaのターン-----
dice...
夏休みが 5 日進んだ。
5日目。
暑い。今日は猛暑日。動く気になれなくてだらだらと。
課題ポイント :    -5 ->   995
充実ポイント :     5 ->    15

-----iiiのターン-----
dice...
夏休みが 3 日進んだ。
3日目。
ちょっと頑張った
課題ポイント :   -20 ->   980
充実ポイント :    10 ->    20

-----uuuのターン-----
dice...
夏休みが 3 日進んだ。
3日目。
ちょっと頑張った
課題ポイント :   -20 ->   980
充実ポイント :    10 ->    20

aaaはイベントに参加しますか？
はい:y | いいえ:n >> y
iiiはイベントに参加しますか？
はい:y | いいえ:n >> n
uuuはイベントに参加しますか？
はい:y | いいえ:n >> y

夏の楽しいイベントの始まりです。
海イベント
サイコロを振ってでた目の数*10の充実ポイントをゲット

aaaのターン
9の目が出た。
aaaに充実ポイント+90!!
-----aaa-----
課題ポイント :   995
充実ポイント :   105
uuuのターン
9の目が出た。
uuuに充実ポイント+90!!
-----uuu-----
課題ポイント :   980
充実ポイント :   110
```


## 考察
最初に構想していた関数仕様では足りない部分が多くあり、プログラムを製作する過程で新たに多くの関数を作ることになってしまった。初期の関数定義が甘かったと思う。

プログラムは、必要最低限の機能を実装した。面白いゲームにするために、 初期ステータスやステータスの変化量、表示など変更を加えなければいけない部分がまだ多くあると考える。


