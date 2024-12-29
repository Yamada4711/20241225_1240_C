#include "shop.h"

#include <iostream>
using namespace std;

int DecideManager(const char* managerName[], int i, Hero& hero)
{
	const char* member[] = { "�E��", "����", "���k", "�m", "�R�m", "��m", "�w��", "��t��" };

	int index = -1;
	do
	{
		cout << managerName[i] << "��S������l�̔ԍ���I�ڂ�" << endl;
		hero.Show();
		cin >> index;
		if (index >= 0 && index <= 7)
		{
			if (hero.GetStatus() & hero.GetJobStatus(index)) break;
		}
		cout << "���̔ԍ��̐l�͍����͋x��ł���悤���B" << endl
			<< endl;
		index = -1;
	} while (true);

	cout << managerName[i] << "��S������̂� " << member[index] << " �Ɍ��܂����B" << endl
		<< endl;
	return hero.GetJobStatus(index);
}

Shop::Shop(Hero& hero)
{
	cout << "���񗈂Ă��ꂽ�����o�[�̓����ɍ��킹�āA�K�؂Ȗ���������U�낤�B" << endl
		<< "�����l���ɕ����̖�����C���Ă��������B" << endl
		<< endl;
	const char* managerName[] = { "�z�[��", "�L�b�`��", "�N���[�}�[", "���W�ł�" };
	for (int i = 0; i < 4; i++)
	{
		manager[i] = DecideManager(managerName, i, hero);
	}
}

void Shop::Event(Hero& hero)
{
	cout << "<< �c�ƊJ�n >>" << endl
		<< endl
		<< "���q���񂪂���Ă����I" << endl
		<< endl
		<< "<< Mission1�F�z�[�� >>" << endl;

	if (manager[0] & hero.GetJobStatus(hero.HERO) || manager[0] & hero.GetJobStatus(hero.RECEPTIONIST)) // �����A�z�[���S�����E�҂���t�삾������
	{
		cout << "�ڋq�͑听�����I" << endl;
		score += 2;
	}
	else if (manager[0] & hero.GetJobStatus(hero.SCHOLAR)) // �����A�z�[���S�����w�҂Ȃ�
	{
		cout << "�ڋq�͂��܂����������悤��" << endl;
	}
	else
	{
		cout << "�܂��܂��̐ڋq��" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission2 : �L�b�`�� >>" << endl;
	if (manager[1] & hero.GetJobStatus(hero.THIEF) ||
		manager[1] & hero.GetJobStatus(hero.WARRIOR)) // �����A�L�b�`���S������������m��������
	{
		cout << "���i�̎���������t�������͑听�����I" << endl;
		score += 2;
	}
	else if (manager[1] & hero.GetJobStatus(hero.MONK) || 
		manager[1] & hero.GetJobStatus(hero.RECEPTIONIST)) // �����A�L�b�`���S�����m����t��Ȃ�
	{
		cout << "�����Ӗ��Ō|�p�I�Ȗ��ɂȂ���" << endl;
	}
	else
	{
		cout << "�܂��܂��̖���" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission3 : �N���[�}�[ >>" << endl;
	if (manager[2] & hero.GetJobStatus(hero.GAMBLER) ||
		manager[2] & hero.GetJobStatus(hero.MONK)) // �����A�N���[�}�[�S�������k���m��������
	{
		cout << "�N���[�}�[�����܂���������߂��I" << endl;
		score += 2;
	}
	else if (manager[2] & hero.GetJobStatus(hero.THIEF) ||
		manager[2] & hero.GetJobStatus(hero.KNIGHT)) // �����A�N���[�}�[�S�����������R�m�Ȃ�
	{
		cout << "�N���[�}�[�͌�������" << endl;
	}
	else
	{
		cout << "�N���[�}�[�ɑޓX�����߂�" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission4 : ���W�ł� >>" << endl;
	if (manager[3] & hero.GetJobStatus(hero.KNIGHT) || 
		manager[3] & hero.GetJobStatus(hero.SCHOLAR)) // �����A���W�ł��S�����R�m���w�҂�������
	{
		cout << "�X�}�[�g�ȉ�v�ōD��ۂ�^�����I" << endl;
		score += 2;
	}
	else if (manager[3] & hero.GetJobStatus(hero.HERO) || 
		manager[3] & hero.GetJobStatus(hero.GAMBLER) || 
		manager[3] & hero.GetJobStatus(hero.WARRIOR)) // �����A���W�ł��S�����E�҂����k����m�Ȃ�
	{
		if (manager[3] & hero.GetJobStatus(hero.GAMBLER))
		{
			cout << "���k�̓��W�̂������������莩���̉��ɓ��ꂽ" << endl;
		}
		else
		{
			cout << "�v�Z�Ɏ�Ԏ��A���W�ɒ��ւ̗񂪂ł��Ă��܂���" << endl;
		}
	}
	else
	{
		cout << "�������Ȃ����W�ł����I����" << endl;
		score++;
	}
	cout << endl;
}

void Shop::ShowResult(Hero& hero)
{
	cout << "<< ���ʔ��\ >>" << endl;
	hero.Show();
	
	cout << "����̃X�R�A > " << score << endl;

	const char* result[] = { "�ǂ��l�I", "�܂��܂��̐l�I", "��œI�Ȑl�I" };

	int index = -1;

	score > 6 ? index = 0 :
	score < 4 ? index = 2 :
				index = 1;

	cout << "���Ȃ��̕]�� > " << result[index] << endl;
}