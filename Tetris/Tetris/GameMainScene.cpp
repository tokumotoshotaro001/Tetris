#include "GameMainScene.h"
#include "DxLib.h"
#include "Block.h"
#include "SceneManager.h"

/********************************************
* マクロ定義
********************************************/

/********************************************
* 型定義
********************************************/

/********************************************
* グローバル変数宣言
********************************************/
int BackGround_image;  //背景画像イメージ
int BackGround_sound;  //BGM
int GameOver_sound;  //ゲームオーバーSE
int Score;  //スコア

/********************************************
* プロトタイプ宣言
********************************************/

/********************************************
* ゲームメイン画面：初期化処理
* 引数：なし
* 戻り値：エラー情報
********************************************/
int GameMainScene_Initialize(void)
{
	int ret = 0;

	ret = Block_Initialize();
	BackGround_image = LoadGraph("image/stage.png");
	BackGround_sound = LoadSoundMem("sounds/BGM017.ogg");
	GameOver_sound=
}