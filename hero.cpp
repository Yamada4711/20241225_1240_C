#include "hero.h"

#include <vector>
using namespace std;

Hero::Hero()
{
	vector<int>job;

	for (int i = 0; i < 8; i++)
	{
		job.push_back(jobStatus[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		int index = rand() % job.size();
		status |= job[index];
		job.erase(job.begin() + index);
	}
}

void Hero::Show()
{
	cout << "<< ����̓X�� >>" << endl;

	const char* member[] = { "0.�E�ҁF�̗�", "1.�����F��p", "2.���k�F���^", "3.�m�F���_��", "4.�R�m�F�^�ʖ�", "5.��m�F����", "6.�w�ҁF���]", "7.��t��F����" };

	for (int j = 0; j < 8; j++)
	{
		if (status & jobStatus[j])
		{
			cout << member[j] << ", " << flush;
		}
	}
	cout << endl;
}

int Hero::GetStatus()
{
	return status;
}

int Hero::GetJobStatus(int index)
{
	return jobStatus[index];
}