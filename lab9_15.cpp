﻿#include <iostream>
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

int* mas_x(int(*a)[n], int* x,		// Функция для определения 
	void (*mas)(int[n][n]))			// массива x
{
	int k, l = 0, zn, c;		// k - сумма каждой строки, l - нужен для цикла по массиву x, 
								// zn - переменная отвечающая за наличие знака, 
								// c - нужна для проверки все ли элементы были с одним знаком
	mas(a);
	for (int i = 0; i < n; i++)
	{
		k = 0;		// После каждой строки переменные обнуляются
		zn = 1;		// для нового посчета значений строки
		c = 0;
		for (int j = 0; j < n; j++)
		{
			if (zn == 1)		// Если число является положительным
			{
				if (a[i][j] >= 0)		// Проверка полезна для первого элемента 
				{						// в строке, когда мы не знаем его знак
					k = k + a[i][j];
					zn = 1; c++;
				}
				else
				{
					zn = -1; c = 1;
					k = a[i][j];
				}
			}
			else if (zn == -1)		// Если число является отрицательным
			{
				if (a[i][j] < 0)
				{
					k = k + a[i][j];
					zn = -1; c++;
				}
			}
		}
	}
	if (c == n)		// Если все числа прошли по одной строке
	{				// то наша переменная c будет равно кличеству чисел в строке
		x[l] = k;		// Если это так, то записываем сумму
		l++;
	}
	else
	{
		x[l] = 0;		// Иначе это 0
		l++;
	}
}
return x;
}