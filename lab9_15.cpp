#include <iostream>
#include <fstream>
using namespace std;

#define n 5

void input_matr(int a[n][n])		// Функция записи массива с клавиатуры
{
	cout << "Введите элементы массива \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "элемент[" << i << "," << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void input_file(int a[n][n])		// Функция записи массива из файла
{
	ifstream f("matr.txt");
	if (!f.is_open())		// Проверка открытия файла
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				f >> a[i][j];
			}
		}
	}
	f.close();		// Закрытие файла
}

