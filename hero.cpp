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
	cout << "<< ¡‰ñ‚Ì“Xˆõ >>" << endl;

	const char* member[] = { "0.—EŽÒF‘Ì—Í", "1.“‘¯FŠí—p", "2.”Ž“kF‹­‰^", "3.‘mF¸_—Í", "4.‹RŽmF^–Ê–Ú", "5.íŽmF‰ö—Í", "6.ŠwŽÒF“ª”]", "7.Žó•tìF–ü‚µ" };

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