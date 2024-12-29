#include "shop.h"

#include <iostream>
using namespace std;

int DecideManager(const char* managerName[], int i, Hero& hero)
{
	const char* member[] = { "勇者", "盗賊", "博徒", "僧", "騎士", "戦士", "学者", "受付嬢" };

	int index = -1;
	do
	{
		cout << managerName[i] << "を担当する人の番号を選ぼう" << endl;
		hero.Show();
		cin >> index;
		if (index >= 0 && index <= 7)
		{
			if (hero.GetStatus() & hero.GetJobStatus(index)) break;
		}
		cout << "その番号の人は今日は休んでいるようだ。" << endl
			<< endl;
		index = -1;
	} while (true);

	cout << managerName[i] << "を担当するのは " << member[index] << " に決まった。" << endl
		<< endl;
	return hero.GetJobStatus(index);
}

Shop::Shop(Hero& hero)
{
	cout << "今回来てくれたメンバーの特徴に合わせて、適切な役割を割り振ろう。" << endl
		<< "同じ人物に複数の役割を任せてもいいぞ。" << endl
		<< endl;
	const char* managerName[] = { "ホール", "キッチン", "クレーマー", "レジ打ち" };
	for (int i = 0; i < 4; i++)
	{
		manager[i] = DecideManager(managerName, i, hero);
	}
}

void Shop::Event(Hero& hero)
{
	cout << "<< 営業開始 >>" << endl
		<< endl
		<< "お客さんがやってきた！" << endl
		<< endl
		<< "<< Mission1：ホール >>" << endl;

	if (manager[0] & hero.GetJobStatus(hero.HERO) || manager[0] & hero.GetJobStatus(hero.RECEPTIONIST)) // もし、ホール担当が勇者か受付嬢だったら
	{
		cout << "接客は大成功だ！" << endl;
		score += 2;
	}
	else if (manager[0] & hero.GetJobStatus(hero.SCHOLAR)) // もし、ホール担当が学者なら
	{
		cout << "接客はいまいちだったようだ" << endl;
	}
	else
	{
		cout << "まあまあの接客だ" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission2 : キッチン >>" << endl;
	if (manager[1] & hero.GetJobStatus(hero.THIEF) ||
		manager[1] & hero.GetJobStatus(hero.WARRIOR)) // もし、キッチン担当が盗賊か戦士だったら
	{
		cout << "普段の自炊が功を奏し調理は大成功だ！" << endl;
		score += 2;
	}
	else if (manager[1] & hero.GetJobStatus(hero.MONK) || 
		manager[1] & hero.GetJobStatus(hero.RECEPTIONIST)) // もし、キッチン担当が僧か受付嬢なら
	{
		cout << "悪い意味で芸術的な味になった" << endl;
	}
	else
	{
		cout << "まあまあの味だ" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission3 : クレーマー >>" << endl;
	if (manager[2] & hero.GetJobStatus(hero.GAMBLER) ||
		manager[2] & hero.GetJobStatus(hero.MONK)) // もし、クレーマー担当が博徒か僧だったら
	{
		cout << "クレーマーをうまく言いくるめた！" << endl;
		score += 2;
	}
	else if (manager[2] & hero.GetJobStatus(hero.THIEF) ||
		manager[2] & hero.GetJobStatus(hero.KNIGHT)) // もし、クレーマー担当が盗賊か騎士なら
	{
		cout << "クレーマーは激高した" << endl;
	}
	else
	{
		cout << "クレーマーに退店を求めた" << endl;
		score++;
	}

	cout << endl
		<< "<< Mission4 : レジ打ち >>" << endl;
	if (manager[3] & hero.GetJobStatus(hero.KNIGHT) || 
		manager[3] & hero.GetJobStatus(hero.SCHOLAR)) // もし、レジ打ち担当が騎士か学者だったら
	{
		cout << "スマートな会計で好印象を与えた！" << endl;
		score += 2;
	}
	else if (manager[3] & hero.GetJobStatus(hero.HERO) || 
		manager[3] & hero.GetJobStatus(hero.GAMBLER) || 
		manager[3] & hero.GetJobStatus(hero.WARRIOR)) // もし、レジ打ち担当が勇者か博徒か戦士なら
	{
		if (manager[3] & hero.GetJobStatus(hero.GAMBLER))
		{
			cout << "博徒はレジのお金をこっそり自分の懐に入れた" << endl;
		}
		else
		{
			cout << "計算に手間取り、レジに長蛇の列ができてしまった" << endl;
		}
	}
	else
	{
		cout << "何事もなくレジ打ちを終えた" << endl;
		score++;
	}
	cout << endl;
}

void Shop::ShowResult(Hero& hero)
{
	cout << "<< 結果発表 >>" << endl;
	hero.Show();
	
	cout << "今回のスコア > " << score << endl;

	const char* result[] = { "良い人選", "まあまあの人選", "壊滅的な人選" };

	int index = -1;

	score > 6 ? index = 0 :
	score < 4 ? index = 2 :
				index = 1;

	cout << "あなたの評価 > " << result[index] << endl;
}