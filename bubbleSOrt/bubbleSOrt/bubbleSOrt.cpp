#include <iostream>

using namespace std;


void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	};
	cout << endl;
};

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
};

void bubbleSort(int *arr,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j< n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			};
		};
	};
};

int main() {
	int arr[] = { 5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	bubbleSort(arr, n);
	printArray(arr, n);
};