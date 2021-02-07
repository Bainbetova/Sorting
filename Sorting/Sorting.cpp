/* Файл ... */
/* Баинбетова Владлена Владиславна */
/* Программа ... */
/* Основной модуль */
/* 07.02.2021 */

#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;

void qsortRecursive(int *arr, int size);

void menu(int *arr);

int* filling_arr(int n);

int charToInt(char c);

int parsingChar(int* size, int defSize, int flag);

void show(int* arr, int n);

int main()
{
	setlocale(LC_ALL, "");
	int *arr = 0;
	int flag = 0, numb = 0;
	int const defSize = 5;
	int size[defSize];
	char count[5];

	system("cls");
	cout << "Введите желаемое количество элементов:";
	cin >> count;
	for (int i = 0; i < 5; i++) {
		if (!(count[i] >= 48 && count[i] <= 57) && count[i] != 0) {
			cout << "Введено недопустимое значение.";
		}
		else if (count[i] == 0) {
			break;
		}
		else {
			flag++;
			size[i] = charToInt(count[i]);
		}
	}
	numb = parsingChar(size, defSize, flag);
	int* arrResult = new int[numb]; // скопировать массив arr сюда
	arr = filling_arr(numb);
	cout << "Элементы до сортировки:";
	show(arr, numb);
	cout << "\nРезультаты сортировок:";
	qsortRecursive(arrResult, numb);
	show(arrResult, numb);
	delete[]arr;
	delete[]arrResult;
	return 0;
}

void qsortRecursive(int *arr, int size) {
	// Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	// Центральный элемент массива
	int mid = arr[size / 2];

	// Делим массив
	do {
		// Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		// В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arr[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (arr[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	// Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		// сортировка левой части
		qsortRecursive(arr, j + 1);
	}
	if (i < size) {
		// сортировка правой части
		qsortRecursive(&arr[i], size - i);
	}
	return;
}

void menu(int *arr) {
	char choice, count;
	int size = 0;
	do {
		system("cls");
		cout << "1. Задать количество элементов\n2. Показать элменты\n3. Отсортировать элементы\n4. Выход\n\nВыберите операцию: ";
		//cin >> choice;
		choice = _getch();
		system("cls");
		switch (choice)
		{
		case '1':
			cout << "Введите желаемое количество элементов:";
			cin >> count;
			if (!(count >= 48 && count <= 57)) {
				cout << "Введено недопустимое значение.";
			}
			else {
				size = (int)count;
				// вызов функции заполнения
			}
			_getch();
			break;
		case '4':
			break;
		default:
			cout << "Такой операции не существует. Для прододжения нажмите любую клавишу...";
			_getch();
			break;
		}
	} while (choice != '4');
	return;
}

int* filling_arr(int n) {
	int *arr = new int[n];
	int num = 0;
	for (int i = 0; i < n; i++) {
		num = rand() % 10000 + 1; // случайные числа от 0 до 10000
		arr[i] = num;
	}
	return arr;
}

int charToInt(char c) {
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	return arr[c - '0'];
}

int parsingChar(int* size, int defSize, int flag) {
	int result = 0;
	for (int i = flag; i > 0; i--) {
		if (i == flag - 4) result += size[i - 1] * 10000;
		if (i == flag - 3) result += size[i - 1] * 1000;
		if (i == flag - 2) result += size[i - 1] * 100;
		if (i == flag - 1) result += size[i - 1] * 10;
		if (i == flag) result += size[i - 1];
	}
	return result;
}

void show(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 0) cout << "\n";
	}
}