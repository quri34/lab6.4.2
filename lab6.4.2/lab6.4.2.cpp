#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}

int Sum(int* a, const int size, int i, int s)
{
	if (a[i] > 0)
		s += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, s);
	else
		return s;
}

int Max(int* a, const int size, int i, int max)
{
	if (abs(a[i]) > abs(max))
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}

int Min(int* a, const int size, int i, int min)
{
	if (abs(a[i]) < abs(min))
		min = a[i];
	if (i < size - 1)
		return Min(a, size, i + 1, min);
	else
		return min;
}

int FindMin(int* a, const int size, int i)
{
	if (a[i] == Min(a, size, 1, a[0]))
		return i;
	if (i < size - 1)
		return FindMin(a, size, i + 1);
}

int FindMax(int* a, const int size, int i)
{
	if (a[i] == Max(a, size, 1, a[0]))
		return i;
	if (i < size - 1)
		return FindMax(a, size, i + 1);
}

int Dobutok(int* a, const int size, int i, int d)
{
	if (i > FindMax(a, size, 0) && i < FindMin(a, size, 0) || i < FindMax(a, size, 0) && i > FindMin(a, size, 0))
		d *= a[i];
	if (i < size - 1)
		return Dobutok(a, size, i + 1, d);
	else
		return d;
}

void FindMaxIndex(int* a, const int size, int& max, int& i_max, int i)
{
	if (i < size)
	{
		if (max < a[i])
		{
			max = a[i];
			i_max = i;
		}
		FindMaxIndex(a, size, max, i_max, i + 1);
	}
}

int Sort(int* a, const int size, int i)
{
	int max = a[i];
	int imax = i;
	FindMaxIndex(a, size, max, imax, i + 1);
	a[imax] = a[i];
	a[i] = max;

	if (i < size - 2)
		Sort(a, size, i + 1);
	return 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int Low;
	int High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;

	Create(a, n, Low, High, 0);
	cout << "a[" << n << "] = {";
	Print(a, n, 0);
	cout << "}" << endl;

	cout << "Сумa додатніх елементів масиву = " << Sum(a, n, 0, 0); cout << endl;
	cout << "Добуток елементів масиву, розташованих між максимальним за модулем і мінімальним за модулем елементами = " << Dobutok(a, n, 0, 1); cout << endl;

	cout << "Елементи масиву, впорядковані за спаданням :" << endl;
	Sort(a, n, 0);

	cout << "a[" << n << "] = {";
	Print(a, n, 0);
	cout << "}" << endl;

	delete[] a;
	return 0;
}
