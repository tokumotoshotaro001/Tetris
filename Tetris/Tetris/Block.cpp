#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"

/********************************************
* �}�N����`
********************************************/
#define FIELD_HEIGHT (21)	//�t�B�[���h�̃}�X�̍���
#define FIELD_WIDTH (12)	//�t�B�[���h�̃}�X�̕�
#define BLOCK_TROUT_SIZE (4)	//�t�B�[���h�̃}�X�T�C�Y
#define BLOCK_SIZE (36)	//1�u���b�N������̃T�C�Y
#define BLOCK_TYPE_MAX (7)	//�����Ă���u���b�N�̎��
#define BLOCK_NEXT_POS_X (700)
#define BLOCK_NEXT_POS_Y (500)
#define BLOCK_STOCK_POS_X (500)
#define BLOCK_STOCK_POS_Y (350)
#define DROP_BLOCK_INIT_X (4)
#define DROP_BLOCK_INIT_Y (-1)
#define DROP_SPEED (60)
#define TURN_CROCKWICE (0)
#define TURN_ANTICROCKWICE (1)