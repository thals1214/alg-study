#include <iostream>

using namespace std;

// case where white starts first
int board(int i, int j, char** arr) {
	int val1 = i; int val2 = j;
	int sum = 0;

	for (int k = i; k < i + 8; k++) {
		for (int l = j; l < j + 8; l++) {
			if (((l-val2)+ (k - val1)) % 2 == 0 ) {
				if(arr[k][l] == 'B') sum++;
			}
			else if (((l - val2) + (k - val1)) % 2 == 1){
				if (arr[k][l] == 'W') sum++;
			}
		}
	}
	return sum;
}

// case where black starts first
int board2(int i, int j, char** arr) {
	int val1 = i; int val2 = j;
	int sum = 0;

	for (int k = i; k < i + 8; k++) {
		for (int l = j; l < j + 8; l++) {
			if (((l - val2) + (k - val1)) % 2 == 0) {
				if (arr[k][l] == 'W') sum++;
			}
			else if (((l - val2) + (k - val1)) % 2 == 1) {
				if (arr[k][l] == 'B') sum++;
			}
		}
	}
	return sum;
}
int main() {
	int N, M;
	cin >> N >> M;
	int sum = 0; bool flag;

	// arr malloc 
	char** arr;
	arr = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * M);
	}
	// putting values inside array 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	// algorithm
	int case1, case2;
	int total, temp = 10000000;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			case1 = board(i, j, arr);
			case2 = board2(i, j, arr);

			total = min(case1, case2);
			
			if (temp > total) temp = total;
		}
	}

	cout << temp;


	// free array  
	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}
	free(arr);

}