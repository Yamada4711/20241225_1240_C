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
	{						// 職業		特徴		得意				苦手
							//-------------------------------------------------------------------------
		HERO = 0,			// 勇者		体力		ホール				レジ打ち
		THIEF = 1,			// 盗賊		器用		キッチン			クレーマー対応
		GAMBLER = 2,		// 博徒		強運		クレーマー対応		レジ打ち
		MONK = 3,			// 僧		精神抵抗	クレーマー対応		キッチン
		KNIGHT = 4,			// 騎士		真面目		レジ打ち			クレーマー対応
		WARRIOR = 5,		// 戦士		筋力		キッチン			レジ打ち
		SCHOLAR = 6,		// 学者		賢さ		レジ打ち			ホール
		RECEPTIONIST = 7,	// 受付嬢	癒し		ホール				キッチン
	};

private:
	int status = 0b00000000; // ステータス(現在のパーティー編成)を入れる変数

	int jobStatus[8] = { 0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001 };

	
};