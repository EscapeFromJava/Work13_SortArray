#include <iostream>
#include <ctime>
using namespace std;
int* createArr(int size);
void printArr(int arr[], int size);
void printDuplicates(int ar[], int size);
void swapElems(int* x, int* y);
void sortFindMin(int ar[], int size);

int main() {
	setlocale(LC_ALL, "rus");
	int size;
	cin >> size;
	int* ar = createArr(size);
	printArr(ar, size);
	cout << " " << endl;
	//ищем повторения
	printDuplicates(ar, size);
	sortFindMin(ar, size);


	delete[] ar;
	return 0;
}

int* createArr(int size)
{
	srand(time(NULL));
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50;
	}
	return arr;
}


void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Элемент массива [" << i << "] равен = " << arr[i] << endl;
	}
}

//функция, которая ищет повторения элементов массива и выводить номера совпадений в консоль

void printDuplicates(int ar[], int size)
{
	int temp;
	for (int i = 0; i < size; i++) {
		temp = ar[i];
		for (int j = i + 1; j < size; j++) {
			if (temp == ar[j])
				cout << temp << " в элементах № " << i << " и № " << j << endl;
		}
	}
}

void swapElems(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

//сортировка массива

//void sortFindMin(int ar[], int size)
//{
//	int temp;
//	for (int i = 0; i < size; i++) {
//		temp = ar[i];
//		for (int j = i + 1; j < size; j++) {
//			if (temp > ar[j]) {
//				temp = ar[j];
//				ar[j] = ar[i];
//				ar[i] = temp;
//			}
//		}
//	}
//	for(int i = 0; i < size; i++) {
//		cout << "Элемент массива [" << i << "] равен = " << ar[i] << endl;
//	}
//}

void sortFindMin(int ar[], int size)
{
	int temp;
	for (int i = 0; i < size; i++) {
		temp = ar[i];
		int min = ar[0], iMin = 0;
		for (int j = i + 1; j < size; j++) {
			if (ar[j] < min) {
				iMin = j;
			}
		}
		if (ar[i] > ar[iMin]) {
			swapElems(&ar[i], &ar[iMin]);
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Элемент массива [" << i << "] равен = " << ar[i] << endl;
	}
}