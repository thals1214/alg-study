#include <iostream>
using namespace std;

int main() {
	int N, M, flag = 0;
	int temp, sum;
	cin >> N >> M;

	int* arr;
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				temp = arr[i] + arr[j] + arr[k];
				if (temp <= M) {
					flag++;
					if (flag == 1) sum = temp;
				}
				if ((temp <= M) && (sum <= temp)) {
					sum = temp;
					if (sum == M) {
						cout << sum;
						free(arr);
						return 0;
					}
				}
				
			}
		}
	}
	cout << sum;
	free(arr);
}