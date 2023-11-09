#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"

/********************************************
* マクロ定義
********************************************/
#define FIELD_HEIGHT (21)	//フィールドのマスの高さ
#define FIELD_WIDTH (12)	//フィールドのマスの幅
#define BLOCK_TROUT_SIZE (4)	//フィールドのマスサイズ
#define BLOCK_SIZE (36)	//1ブロック当たりのサイズ
#define BLOCK_TYPE_MAX (7)	//落ちてくるブロックの種類
#define BLOCK_NEXT_POS_X (700)
#define BLOCK_NEXT_POS_Y (500)
#define BLOCK_STOCK_POS_X (500)
#define BLOCK_STOCK_POS_Y (350)
#define DROP_BLOCK_INIT_X (4)
#define DROP_BLOCK_INIT_Y (-1)
#define DROP_SPEED (60)
#define TURN_CROCKWICE (0)
#define TURN_ANTICROCKWICE (1)