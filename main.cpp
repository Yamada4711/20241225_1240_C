// 勇者等を召喚して店で働かせるシミュレーション
// 
// 20241225 進捗
// ショップ店員の仕事の割り振りまで終わった。
// 次回はイベントを実装する予定



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