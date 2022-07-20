#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[10] = {0,};
	int temp,sum = 0, i = 0;

	for (int j = 1; j < N; j++) {
		temp = j;
		i = 0;
		sum = 0;
		while (temp != 0) {
			arr[i] = temp % 10;
			temp = temp / 10;
			if (temp < 10) {
				arr[i + 1] = temp;
				i++;
				break;
			}
			i++;
		}
		sum += j;
		for (int k = 0; k <= i; k++) {
			sum += arr[k];
		}
		if (sum == N) {
			cout << j;
			return 0;
		}
	}

	cout << 0;
	return 0;

}