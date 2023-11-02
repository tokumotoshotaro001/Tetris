#include "InputControl.h"
#include "DxLib.h"

/********************************************
* �}�N����`
********************************************/
#define XINPUT_BUTTON_MAX(16)  //�R���g���[���[�̃{�^����

/********************************************
* �^��`
********************************************/
enum KEY_STATE
{
	E_NONE,  //������
	ECLICK,  //�������u��
	E_PRESS,  //���������Ă�
	E_RELEASED,  //������
	E_KEY_STATE_MAX
};

/********************************************
* �ϐ��錾
********************************************/
KEY_STATE button_state[XINPUT_BUTTON_MAX];

/********************************************
* �v���g�^�C�v�錾
********************************************/

/********************************************
* ���͐���@�\�F����������
* �����F�Ȃ�
* �߂�l�F�Ȃ�
********************************************/
void InputControl_Initialize(void)
{
	int i;  //���[�v�J�E���^

	//���͏�Ԃ̏�����
	for (i = 0; i < XIPUT_BUTTON_MAX; i++)
	{
		button_state[i] = E_NONE;
	}
}

/********************************************
* ���͐���@�\�F�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�
********************************************/
void InputControl_Update(void)
{
	int i;
	XINPUT_STATE input_controller;

	//�R���g���[���[�̓��͂��擾
	GetjoypadXInputState(DX_INPUT_PAD1, &input_controller);

	//���͏�Ԃ̍X�V
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		if (input_controller.Buttons[i] == TRUE)
		{
			switch(button_state[i])
			{
				case E_NONE:
				case E_RELEASED:
					button_state[i] = E_CLICK;
					break;
				case E_CLICK:
				case E_PRESS:
					button_state[i] = E_PRESS;
					break;
				default:
					button_state[i] = E_NONE;
					break;
			}
		}
		else
		{
			switch(button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_NONE;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_PRESS;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
	}
}

/********************************************
* ���͐���@�\�F������Ă��邩���菈��
* �����FXINPUT�̃{�^�����
* XINPUT�QBUTTON_DPAD_UP  (0)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_DOWN  (1)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_LEFT  (2)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_RIGHT  (3)  //�f�W�^�������{�^���E
* XINPUT�QBUTTON_STATE  (4)  //STATE�{�^��
* XINPUT�QBUTTON_BACK  (5)  //BACK�{�^��
* XINPUT�QBUTTON_LEFT_THUMB  (6)  //���X�e�B�b�N��������
* XINPUT�QBUTTON_RIGHT_THUMB  (7)  //�E�X�e�B�b�N��������
* XINPUT�QBUTTON_LEFT_SHOULDER  (8)  //LB�{�^��
* XINPUT�QBUTTON_RIGHT_SHOULDER  (9)  //RB�{�^��
* XINPUT�QBUTTON_A  (12)  //A�{�^��
* XINPUT�QBUTTON_B  (13)  //B�{�^��
* XINPUT�QBUTTON_X  (14)  //X�{�^��
* XINPUT�QBUTTON_Y  (15)  //Y�{�^��
* �߂�l�FTRUE(������Ă�j�AFALSE(������ĂȂ��j
********************************************/
int GetButton(int button)
{
	int ret = FALSE;

	if (button_state[button] == E_CLICK || button_state[button] == E_PRESS)
	{
		ret = TRUE;
	}
	return ret;
}

/********************************************
* ���͐���@�\�F�������u�Ԃ����菈��
* �����FXINPUT�̃{�^�����
* XINPUT�QBUTTON_DPAD_UP  (0)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_DOWN  (1)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_LEFT  (2)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_RIGHT  (3)  //�f�W�^�������{�^���E
* XINPUT�QBUTTON_STATE  (4)  //STATE�{�^��
* XINPUT�QBUTTON_BACK  (5)  //BACK�{�^��
* XINPUT�QBUTTON_LEFT_THUMB  (6)  //���X�e�B�b�N��������
* XINPUT�QBUTTON_RIGHT_THUMB  (7)  //�E�X�e�B�b�N��������
* XINPUT�QBUTTON_LEFT_SHOULDER  (8)  //LB�{�^��
* XINPUT�QBUTTON_RIGHT_SHOULDER  (9)  //RB�{�^��
* XINPUT�QBUTTON_A  (12)  //A�{�^��
* XINPUT�QBUTTON_B  (13)  //B�{�^��
* XINPUT�QBUTTON_X  (14)  //X�{�^��
* XINPUT�QBUTTON_Y  (15)  //Y�{�^��
* �߂�l�FTRUE(�������u�ԁj�AFALSE(�������u�Ԃł͂Ȃ��j
********************************************/
int GetButtonDown(int button)
{
	int ret = FALSE;

	if (button_state[button] == E_CLICK)
	{
		ret = TRUE;
	}
	return ret;
}

/********************************************
* ���͐���@�\�F�����������菈��
* �����FXINPUT�̃{�^�����
* XINPUT�QBUTTON_DPAD_UP  (0)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_DOWN  (1)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_LEFT  (2)  //�f�W�^�������{�^����
* XINPUT�QBUTTON_DPAD_RIGHT  (3)  //�f�W�^�������{�^���E
* XINPUT�QBUTTON_STATE  (4)  //STATE�{�^��
* XINPUT�QBUTTON_BACK  (5)  //BACK�{�^��
* XINPUT�QBUTTON_LEFT_THUMB  (6)  //���X�e�B�b�N��������
* XINPUT�QBUTTON_RIGHT_THUMB  (7)  //�E�X�e�B�b�N��������
* XINPUT�QBUTTON_LEFT_SHOULDER  (8)  //LB�{�^��
* XINPUT�QBUTTON_RIGHT_SHOULDER  (9)  //RB�{�^��
* XINPUT�QBUTTON_A  (12)  //A�{�^��
* XINPUT�QBUTTON_B  (13)  //B�{�^��
* XINPUT�QBUTTON_X  (14)  //X�{�^��
* XINPUT�QBUTTON_Y  (15)  //Y�{�^��
* �߂�l�FTRUE(�������u�ԁj�AFALSE(�������u�Ԃł͂Ȃ��j
********************************************/
int GetButtonUp(int button)
{
	int ret = FALSE;

	if (button_state[button] == E_RELEASED)
	{
		ret = TRUE;
	}
	return ret;
}

/********************************************
* ���͐���@�\�F�Q�[���I���p�̃{�^�����菈��
* �����F�Ȃ�
* �߂�l�FTRUE(�������u�ԁj�AFALSE(�������u�Ԃł͂Ȃ��j
********************************************/
int GetExitButton(void)
{
	int ret = FALSE;
	
	if ((GetButtonDown(XINPUT_BUTTON_BACK) == TRUE) || (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE))
	{
		ret = TRUE;
	}
	return ret;
}