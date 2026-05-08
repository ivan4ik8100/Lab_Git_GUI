#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	setlocale(0, "RU");
	srand(time(0));

	vector <int> Victor = {};
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
			int x = rand() % 21 - 10;
			Victor.push_back(x);
			cout << setw(4) << Victor.at(i);
		}
		cout << endl << endl;
		ofstream file("OpenTheDorThree.txt");
		int srednie = (coll_yach / 2) - 1;
		Victor.erase(Victor.begin() + srednie);
		if (!file.is_open())
		{
			return 1;
		}
		
		for (int i = 0; i < coll_yach-1; i++)
		{
			cout << setw(4) << Victor.at(i);
			file << Victor.at(i) << "\t";
		}
		file.close();
		cout << endl << endl << "Виктор сохранен!" << endl;
	}
	int coll_yach1;
	cout << "Количество ячеек = ";
	cin >> coll_yach1;
	if (coll_yach1 <= 0)
	{
		cout << "Такого вектора не сущесвует";
	}
	else
	{
		vector <int> Victor2 = {};
		for (int i = 0; i < coll_yach1; i++)
		{
			int x = rand() % 21 - 10;
			Victor2.push_back(x);
			cout << setw(4) << Victor2.at(i);
		}
		cout << endl << endl;
		for (int i = 0; i < coll_yach1; i++)
		{
			if ((Victor2.at(i) > 0) and (Victor2.at(i) % 2 == 0))
			{
				Victor2.erase(Victor2.begin() + i);
				i = i - 1;
				coll_yach1 = coll_yach1 - 1;
			}
		}
		coll_yach1 = Victor2.size();
		ofstream files("OpenTheDorThree.txt", ios::app);
		files << "\n";
		for (int i = 0; i < coll_yach1; i++)
		{
			cout << setw(4) << Victor2.at(i);
			files << Victor2.at(i) << "\t";
		}
		files.close();
		cout << endl << endl << "Виктор изменен!";
	}
	return 0;
}