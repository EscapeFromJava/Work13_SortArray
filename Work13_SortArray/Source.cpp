#include <iostream>
#include <ctime>
using namespace std;
int* createArr(int size);
void printArr(int arr[], int size);
void printDuplicates(int ar[], int size);
void swapElems(int* x, int* y);
int* sortFindMin(int ar[], int size);

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int size;
	cin >> size;
	int* ar = createArr(size);
	printArr(ar, size);
	cout << " " << endl;
	printDuplicates(ar, size);
	cout << " " << endl;
	sortFindMin(ar, size);
	printArr(ar, size);
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

int* sortFindMin(int ar[], int size)
{
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (ar[j] > ar[j + 1]) {
				swapElems(&ar[j], &ar[j+1]);
			}
		}
	}
	return ar;
}