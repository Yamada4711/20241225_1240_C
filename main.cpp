// �E�ғ����������ēX�œ�������V�~�����[�V����
// 
// 20241225 �i��
// �V���b�v�X���̎d���̊���U��܂ŏI������B
// ����̓C�x���g����������\��



#include "hero.h"
#include "shop.h"

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Hero hero;

	hero.Show();
	Shop shop(hero);

	shop.Event(hero);
	shop.ShowResult(hero);
}