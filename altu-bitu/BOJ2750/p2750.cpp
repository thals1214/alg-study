#include <iostream>
#include <vector>

using namespace std;
// array to be sorted
vector<int> arr;

// Bubble Sort
void bubbleSort(int n) {
	for (int i = 0; i < n; i++) {
		// 0 ~ n-1 까지 정렬
		for (int j = 1; j < n-i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}
// improved bubble sort
void bubbleSortAdv(int n) {
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		bool flag = true;
		// 0 ~ n-1 까지 정렬
		for (int j = 1; j < n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				flag = false;
				swap(arr[j - 1], arr[j]);
			}
			cnt++;
		}
		if (flag) {
			break;
		}
	}
	cout << cnt << "\n ";
}
int main() {
	int n; 

	cin >> n;
	arr.assign(n, 0); // initialize value to 0
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//bubbleSort(n);
	bubbleSortAdv(n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}