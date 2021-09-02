#include <iostream>

using namespace std;

// 시간 초과 

void num_fibonacci(int n) {
	int zeros = 0, ones = 0;
	int temp0 = 0, temp1 = 0;
	int before0 = 0, before1 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			zeros = 1;
			before0 = 1;
		}
		else if (i == 1) {
			zeros = 0;
			temp0 = 0;
		}
		else {
			zeros = temp0 + before0;
		}
		
	}

	
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