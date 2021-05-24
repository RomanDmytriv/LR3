/*7. Перевантажити операції < (порівняння двох списків за сумою елементів), += (додавання елемента в кінець списку),
відсортувати масив екземплярів класу списків за спаданням сум з використанням алгоритму сортування вибором,
додати до списку з найбільшою сумою елементи списку з найменшою сумою.*/
#include <iostream>
#include <Windows.h>

using namespace std;
class MASS2;
class MASS1
{
private:
	int MAX = 30;
	int* MAS;
	int rMAX;
	int summ;
	int min = 0;
	int buf = 0;

public:
	int k;
	MASS1()
	{
		MAS = new int[MAX];
		for (int i = 0; i < MAX; i++) {
			MAS[i] = 0;
		}
	}
	void GetMAS()
	{
		cout << "\n\tВведіть елементи для 1 масиву:\n";
		for (int i = 0, numb; i < MAX; i++) {
			cout << i + 1 << " елемент масиву: ";
			cin >> numb;
			if (numb == 0) {
				break;
			}
			else {
				MAS[i] = numb;
				rMAX++;
			}
		}
	}
	int SendNumb(int i)
	{
		return MAS[i];
	}
	int AddNumbMAS(int number)
	{
		if (rMAX > MAX) return 0;
		else
			MAS[rMAX] = number;
		rMAX++;
	}
	int SummMAS()
	{
		for (int i = 0; i < rMAX; i++) {
			summ += MAS[i];
		}
		return summ;
	}
	int GetSize()
	{
		return rMAX;
	}

	void PrintMAS()
	{
		cout << " \n Перший список:\n";
		for (int i = 0; i < rMAX; i++) {
			cout << i + 1 << "." << MAS[i] << endl;
		}
	}
	void SortMAS()
	{
		for (int i = 0; i < rMAX; i++)
		{
			min = i;
			for (int j = i + 1; j < rMAX; j++)
				min = (MAS[j] < MAS[min]) ? j : min;
			if (i != min)
			{
				buf = MAS[i];
				MAS[i] = MAS[min];
				MAS[min] = buf;
			}
		}
	}
	friend MASS1 operator<(const MASS1&, const MASS2&);
	~MASS1() {}
};
class MASS2

{

private:
	int MAX = 30;
	int* MAS;
	int rMAX;
	int summ;
	int min = 0;
	int buf = 0;

public:
	MASS2()
	{
		MAS = new int[MAX];
		for (int i = 0; i < MAX; i++) {
			MAS[i] = 0;
		}
	}
	void GetMAS()
	{
		cout << "\n\tВведіть елементи для 2 масиву:\n";
		for (int i = 0, numb; i < MAX; i++) {
			cout << i + 1 << " елемент масиву: ";
			cin >> numb;
			if (numb == 0) {
				break;
			}
			else {
				MAS[i] = numb;
				rMAX++;
			}
		}
	}
	int SendNumb(int i)
	{
		return MAS[i];
	}
	int AddNumbMAS(int number)
	{
		if (rMAX > MAX) return 0;
		else
			MAS[rMAX] = number;
		rMAX++;
	}
	int SummMAS()
	{
		for (int i = 0; i < rMAX; i++) {
			summ += MAS[i];
		}
		return summ;
	}
	int GetSize()
	{
		return rMAX;
	}
	void PrintMAS()
	{
		cout << " \n Другий список:\n";
		for (int i = 0; i < rMAX; i++) {
			cout << i + 1 << "." << MAS[i] << endl;
		}
	}
	void SortMAS()
	{
		for (int i = 0; i < rMAX; i++)
		{
			min = i;
			for (int j = i + 1; j < rMAX; j++)
				min = (MAS[j] < MAS[min]) ? j : min;
			if (i != min)
			{
				buf = MAS[i];
				MAS[i] = MAS[min];
				MAS[min] = buf;
			}
		}
	}
	friend MASS1 operator<(const MASS1&, const MASS2&);
	~MASS2() {}
};
MASS1 operator <(const MASS1& mm1, const MASS2& mm2)
{
	MASS1 temp;
	if (mm1.summ < mm2.summ) {
		temp.k = 1;
	}
	else {
		temp.k = 0;
	}
	return temp;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MASS1 m1;
	MASS2 m2;
	m1.GetMAS();
	m2.GetMAS();
	if (m1.k == 0) {
		for (int i = 0, temp = 0, size = m2.GetSize(); i < size; i++) {
			temp = m2.SendNumb(i);
			m1.AddNumbMAS(temp);
		}
		cout << "\nCума 2 списку менша за суму 1 списку";
		m1.SortMAS();
		m1.PrintMAS();
	}
	else {
		for (int i = 0, temp = 0, size = m1.GetSize(); i < size; i++) {
			temp = m1.SendNumb(i);
			m2.AddNumbMAS(temp);
		}
		cout << "\nCума 1 списку менша за суму 2 списку";
		m2.SortMAS();
		m2.PrintMAS();
	}
	return 0;
}