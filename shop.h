#pragma once

#include "hero.h"

class Shop
{
public:
	Shop(Hero& hero);
	void Event(Hero& hero);
	void ShowResult(Hero& hero);

private:
	int score = 0;

	// �S���҂��i�[����ϐ�
	int manager[4];
};