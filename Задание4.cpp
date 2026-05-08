#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
void max_el(const vector<int>& V)
{
	auto max = max_element(V.begin(), V.end());
	cout << endl << "Максимальный элемент: " << *max << endl;
}
void min_el(const vector<int>& V)
{
	auto min = min_element(V.begin(), V.end());
	cout << endl << "Минимальный элемент: " << *min << endl;
}
void max_ind(const vector<int>& V,int coll_yach)
{
	vector<int> max_s;
	int cnt = 0;
	auto max = max_element(V.begin(), V.end());
	for (int i = 0; i < coll_yach; i++)
	{
		if (V.at(i) == *max)
		{
			max_s.push_back(i);
			cnt += 1;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		int x = max_s.at(i);
		cout << endl << "Максимальный элемент расположен на " << x << " индексе.";
	}
	cout << endl;
	max_s.clear();
}
void min_ind(const vector<int>& V, int coll_yach)
{
	vector<int> max_s;
	int cnt = 0;
	auto min = min_element(V.begin(), V.end());
	for (int i = 0; i < coll_yach; i++)
	{
		if (V.at(i) == *min)
		{
			max_s.push_back(i);
			cnt += 1;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		int x = max_s.at(i);
		cout << endl << "Минимальный элемент расположен на " << x << " индексе.";
	}
	cout << endl;
	max_s.clear();
}
void find_elem(const vector<int>& V, int coll_yach)
{
	vector<int> max_s;
	int cnt = 0;
	int c;
	cout << endl << "Какой число найти? ";
	cin >> c;
	for (int i = 0; i < coll_yach; i++)
	{
		if (V.at(i) == c)
		{
			max_s.push_back(i);
			cnt += 1;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		int x = max_s.at(i);
		cout << endl << "Данное число расположена на " << x << " индексе.";
	}
	cout << endl;
	max_s.clear();
}
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
		int x = 1;
		while (x == 1)
		{
			if (Victor.empty())
			{
				for (int i = 0; i < coll_yach; i++)
				{
					int x = rand() % 21 - 10;
					Victor.push_back(x);
				}
			}
			for (int i = 0; i < coll_yach; i++)
			{
				cout << setw(4) << Victor.at(i);
			}
			cout << endl << endl;
			int Deistv;
			cout << "Выберите действие:" << endl;
			cout << "1. Максимальное число;" << endl;
			cout << "2. Минимальное число;" << endl;
			cout << "3. Позиция максимального числа;" << endl;
			cout << "4. Позиция минимального числа;" << endl;
			cout << "5. Позиция заданного числа;" << endl;
			cout << "6. Повторить с новыми числами;" << endl;
			cout << "7. Выход;" << endl;
			cin >> Deistv;
			
			
			switch (Deistv)
			{
			case 1: 
				max_el(Victor); break;
			case 2:	
				min_el(Victor); break;
			case 3: 
				max_ind(Victor, coll_yach);
				break;
			case 4:
				min_ind(Victor, coll_yach);
				break;
			case 5:
				find_elem(Victor, coll_yach);
				break;
			case 6:
				cout << "Пересборка вектора.";
				Victor.clear(); break;
			case 7: 
				x = 0; 
				cout << "Выход из программы."; break;
			default: 
				cout << "Такой действия не существует."; break;
			}
			system("pause");
			system("cls");
		}
		
	}
	return 0;
}