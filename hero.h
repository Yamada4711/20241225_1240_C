#pragma once

#include <iostream>

class Hero
{
public:
	Hero();

	void Show();

	int GetStatus();

	int GetJobStatus(int index);
	
	enum Job
	{						// �E��		����		����				���
							//-------------------------------------------------------------------------
		HERO = 0,			// �E��		�̗�		�z�[��				���W�ł�
		THIEF = 1,			// ����		��p		�L�b�`��			�N���[�}�[�Ή�
		GAMBLER = 2,		// ���k		���^		�N���[�}�[�Ή�		���W�ł�
		MONK = 3,			// �m		���_��R	�N���[�}�[�Ή�		�L�b�`��
		KNIGHT = 4,			// �R�m		�^�ʖ�		���W�ł�			�N���[�}�[�Ή�
		WARRIOR = 5,		// ��m		�ؗ�		�L�b�`��			���W�ł�
		SCHOLAR = 6,		// �w��		����		���W�ł�			�z�[��
		RECEPTIONIST = 7,	// ��t��	����		�z�[��				�L�b�`��
	};

private:
	int status = 0b00000000; // �X�e�[�^�X(���݂̃p�[�e�B�[�Ґ�)������ϐ�

	int jobStatus[8] = { 0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001 };

	
};