#include <iostream>
#include <vector>
#include <cmath> // sqrt 사용

const int SIZE = 5000000;

using namespace std;

// 소수 경로 저장해서 리턴하는 함수
vector<int> isPrime() {
	vector<int> prime(SIZE, 0);

	for (int i = 2; i <= SIZE; i++) 
		prime[i] = i;

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) {
			for (int j = i * i; j <= SIZE; j+= i) { // i의배수를
				if (prime[j] == j) //지정된 소수가 없다면
					prime[j] = i;
			}
		}
	}
	return prime;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	// 입력
	cin >> n;

	// 미리 최대 크기까지의 소수 경로 저장 
	vector<int> prime = isPrime();

	while (n--) {
		//소인수분해할 수 입력
		cin >> k;
		// 소이수분해 결과 출력
		while (k > 1) {
			cout << prime[k] << ' ';
			k = k / prime[k];
		}
		cout << '\n';
	}
}