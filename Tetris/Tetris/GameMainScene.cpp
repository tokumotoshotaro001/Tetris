#include "GameMainScene.h"
#include "DxLib.h"
#include "Block.h"
#include "SceneManager.h"

/********************************************
* �}�N����`
********************************************/

/********************************************
* �^��`
********************************************/

/********************************************
* �O���[�o���ϐ��錾
********************************************/
int BackGround_image;  //�w�i�摜�C���[�W
int BackGround_sound;  //BGM
int GameOver_sound;  //�Q�[���I�[�o�[SE
int Score;  //�X�R�A

/********************************************
* �v���g�^�C�v�錾
********************************************/

/********************************************
* �Q�[�����C����ʁF����������
* �����F�Ȃ�
* �߂�l�F�G���[���
********************************************/
int GameMainScene_Initialize(void)
{
	int ret = 0;

	ret = Block_Initialize();
	BackGround_image = LoadGraph("image/stage.png");
	BackGround_sound = LoadSoundMem("sounds/BGM017.ogg");
	GameOver_sound=
}