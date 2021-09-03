#include <iostream>

using namespace std;

// 시간 초과 

void num_fibonacci(int n) {
	int zeros = 0, ones = 0;
	int temp, before;
	int temp2, before2;
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			// zeros 
			zeros = 1;
			before = 1;
			// ones
			ones = 0;
			before2 = 0;
		}
		else if (i == 1) {
			// zeros
			zeros = 0;
			temp = 0;
			// ones
			ones = 1;
			temp2 = 1;
		}
		else {
			// zeros
			zeros = temp + before;
			before = temp;
			temp = zeros;
			// ones
			ones = temp2 + before2;
			before2 = temp2;
			temp2 = ones;
		}
	}
	cout << zeros << " " << ones << "\n";
}

int main() {
	int T; // number of test case
	int N; // number to be tested

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		num_fibonacci(N);
	}
}