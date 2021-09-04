#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr, sorted;

void printArr(int start, int end, string tag) {
	cout << tag << " array : ";
	for (int i = start; i <= end; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}

void merge(int left, int mid, int right) {
	int p1 = left, p2 = mid + 1, p3 = left;

	while (p1 <= mid && p2 <= right) {
		if (arr[p1] <= arr[p2])
			sorted[p3++] = arr[p1++];
		else
			sorted[p3++] = arr[p2++];
	}
	// elements left after comparing procedure 
	while (p1 <= mid)
		sorted[p3++] = arr[p1++];
	while (p2 <= right)
		sorted[p3++] = arr[p2++];
	// copying 
	for (int i = left; i <= right; i++)
		arr[i] = sorted[i];
}
void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid); //왼쪽 배열
		mergeSort(mid + 1, right); //오른쪽 배열
		// printing arr before sorted
		printArr(left, mid, "Left");
		printArr(mid + 1, right, "Right");
		// merge
		merge(left, mid, right); 
		// printing arr after Merged
		printArr(left, right, "Merged");
		cout << "\n";
	}
}
int main() {
	int n;

	cin >> n;
	arr.assign(n, 0);
	sorted.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(0, n - 1);
	//sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}