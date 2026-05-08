#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	setlocale(0, "RU");
	srand(time(0));
	
	vector <double> Victor = {};
	int coll_yach;
	cout << "Количество ячеек = ";
	cin >> coll_yach;
	if (coll_yach <= 0)
	{
		cout << "Такого вектора не сущесвует";
	}
	else
	{
		for (int i = 0; i < coll_yach; i++)
		{
			double x = rand() % 21 - 10;
			Victor.push_back(x);
			cout << setw(4) << Victor.at(i);
		}
		cout << endl << endl;
		ofstream file("OpenTheDor.txt");
		if (!file.is_open())
		{
			return 1;
		}
		double firstN(0), firstI;
		for (int i = 0; i < coll_yach + 5; i++)
		{
			if (i < 5)
			{
				Victor.push_back(81);
			}
			cout << setw(4) << Victor.at(i);
			file << Victor.at(i) << "\t";
			if (Victor.at(i) > 0 and firstN == 0)
			{
				firstN = Victor.at(i);
				firstI = i;
			}
		}
		file.close();
		cout << endl << endl << "Виктор сохранен!" << endl;
		ofstream files("OpenTheDor.txt", ios::app);
		if (!files.is_open())
		{
			return 1;
		}
		Victor.push_back(firstN);
		Victor.push_back(firstI);
		files << endl;
		for (int i = 0; i < coll_yach + 7; i++)
		{
			cout << setw(4) << Victor.at(i);
			files << Victor.at(i) << "\t";
		}
		files.close();
		cout << endl << endl << "Виктор изменен!" << endl;
	}
	return 0;
}