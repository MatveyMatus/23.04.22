#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N,
		x,
		y,
		t = 0,
		time = 0;
	cout << "Введите число страниц от 1 до 2*10^8: ";
	cin >> N;
	cout << "Введите время копирования первого ксерокса от 1 до 10: ";
	cin >> x;
	cout << "Введите время копирования второго ксерокса от 1 до 10: ";
	cin >> y;

	if (x > y) {
		t = x;
		x = y;
		y = t;
	}

	int right = 1;
	time = right;
	while (time / x + ((time - x) / y) < N) {
		right *= 2;
		time = right;
	}

	int left = right / 2;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		time = mid;
		if (time / x + ((time - x) / 2) < N) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << right;
}