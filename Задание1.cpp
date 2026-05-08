#include <iostream>
#include <iomanip>
#include <vector>

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
		cout << "Такого вектора не существует";
	}
	else
	{
		for (int i = 0; i < coll_yach; i++)
		{
			Victor.push_back(rand() % 21 - 10);
			cout << Victor.at(i) << setw(4);
		}
		int seredina = (coll_yach / 2) - 1;
		int Polovina1(0), Polovina2(0);
		for (int i = 0; i < coll_yach; i++)
		{
			if ((i < seredina) and (Victor.at(i) < 0))
			{
				Polovina1 += Victor.at(i);
			}
			if ((i >= seredina) and (Victor.at(i) < 0))
			{
				Polovina2 += Victor.at(i);
			}
		}
		cout << endl << "Первая половина = " << Polovina1 << endl;
		cout << "Вторая половина = " << Polovina2 << endl;
	}
	return 0;
}