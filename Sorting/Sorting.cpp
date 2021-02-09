/* Файл Sorting */
/* Баинбетова Владлена Владиславна */
/* Программа Sorting */
/* Основной модуль */
/* 07.02.2021 */

#include "Sorting.h"

void qsortRecursive(int *arr, int size);

void menu(int *arr);

int* filling_arr(int n);

int charToInt(char c);

int parsingChar(int* size, int defSize, int flag);

void show(int* arr, int n);

int* copyArray(int* arr, int n);

void coctailSort(int *arr, int size);

void coctailSort(int *arr, int size);

int main() {
	setlocale(LC_ALL, "");
	int *arr = 0;
	int flag = 0, numb = 0;
	int const defSize = 5;
	int size[defSize];
	char count[9];

	system("cls");
	cout << "Введите желаемое количество элементов:";
	cin >> count;
	for (int i = 0; i < 5; i++) {
		if (!(count[i] >= 48 && count[i] <= 57) && count[i] != 0) {
			cout << "Введено недопустимое значение.";
		} else if (count[i] == 0) {
			break;
		} else {
			flag++;
			size[i] = charToInt(count[i]);
		}
	}
	numb = parsingChar(size, defSize, flag);	
	arr = filling_arr(numb);
	int* arrResult = copyArray(arr, numb); 
	int* arrCoct = copyArray(arr, numb);
	int* arrShell = copyArray(arr, numb);
	//cout << "Элементы до сортировки:";
	//show(arr, numb);
	cout << "\nРезультаты времени работы сортировок";
	
	clock_t start = clock();
	qsortRecursive(arrResult, numb);
	clock_t finish = clock();
	cout << "\nБыстрая сортировка: " << (double)(finish - start) / CLOCKS_PER_SEC;
	
	start = clock();
	coctailSort(arrCoct, numb);
	finish = clock();
	cout << "\nШейкер сортировка: " << (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	ShellSort(arrShell, numb);
	finish = clock();
	cout << "\nCортировка Шелла: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	//cout << "\nОтсортированный массив: ";
	//show(arrShell, numb);

	delete[]arr;
	delete[]arrResult;
	delete[]arrCoct;
	delete[]arrShell;

	return 0;
}

// Быстрая сортировка
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
			} else {
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

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		num = rand() % 100000 + 1; // случайные числа от 0 до 100 000
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
		if (i == flag - 9) result += size[i - 1] * 1000000000;
		if (i == flag - 8) result += size[i - 1] * 100000000;
		if (i == flag - 7) result += size[i - 1] * 10000000;
		if (i == flag - 6) result += size[i - 1] * 1000000;
		if (i == flag - 5) result += size[i - 1] * 100000;
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
		if (i % 20 == 0) cout << "\n";
	}
}

int* copyArray(int* arr, int n) {
	int* arrRes = new int[n];
	for (int i = 0; i < n; i++) {
		arrRes[i] = arr[i];
	}
	return arrRes;
}

// Шейкер-сортировка
void coctailSort(int *arr, int size) {
	int buff;
	int control = size;
	int left = 0;
	int right = size - 1;
	do {
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
				control = i;
			}
		}
		right = control;
		for (int i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
				buff = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buff;
				control = i;
			}
		}
		left = control;
	} while (left < right);
	return;
}

// Сортировка Шелла
void ShellSort(int *arr, int size) {
	for (int s = size / 2; s > 0; s /= 2) {
		for (int i = 0; i < size; i++) {
			for (int j = i + s; j < size; j += s) {
				if (arr[i] > arr[j]) {
					int temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}
	return;
}