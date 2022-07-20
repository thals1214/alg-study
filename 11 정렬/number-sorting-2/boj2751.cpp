#include <iostream>
#define MAX 1000001

using namespace std;
int sorted[MAX] = { 0, };

// merge sort 직접 구현한것 
void merge(int* list, int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// Merge split-sorted arrays
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	// Copy remaining data
	if (i > mid)
		for (int l = j; j <= right; l++)
			sorted[k++] = list[l];
	else
		for (int l = i; l <= mid; l++) 
			sorted[k++] = list[l];

	// Copy list of array sorted[] to array list[]
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		}
}
void merge_sort(int* list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
int main() {
	int N;
	cin >> N;

	// array before sorted 
	int* list;
	list = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	merge_sort(list, 0, N-1); // list, left, right

	for (int i = 0; i < N; i++) {
		cout << list[i] << "\n";
	}

	free(list);
}