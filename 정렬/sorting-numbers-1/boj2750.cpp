#include <iostream>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

using namespace std;

void selection_sort(int* list, int n) {
	int least, temp;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			SWAP(list[i], list[least], temp);
		}
	}
}

void insertion_sort(int* list, int n) {
	int i, j ,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

int main() {
	int N;
	cin >> N;

	int* arr;
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//selection_sort(arr, N);
	insertion_sort(arr, N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	free(arr);
}