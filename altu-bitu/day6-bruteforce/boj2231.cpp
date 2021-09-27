#include <iostream>

using namespace std;

int constructor(int n) {
	// n까지 분해합 모두 구해보기 
	for (int i = 1; i < n; i++) {
		int k = i; // i는 가공하면 안되므로 k에 저장
		int sum = i;
		while (k > 0) {
			sum += (k % 10);
			k /= 10;
		}
		if (sum == n) // 분해합이 n이라면 바로 생성자 (i) 리턴
			return i;
	}
	return 0;
}

int main() {
	int n; 
	cin >> n;

	cout << constructor(n) << '\n';
}