#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 채에서k번째 지우기 
int isPrime(int n, int k) {
	vector<bool> is_prime(n + 1, true); // index가 0부터 시작
	int cnt = 0;
	// 제곱근까지 검사할 경우: k번쨰 지워지는 제곱근이 제곱근 이상의 소수 i *i <= n 으로 
	// 하면 오류나옴 

	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i; j <= n; j += i) {
				if (!is_prime[j])// 이미 지워진 수라면 넘어감
					continue;
				is_prime[j] == false;
				if (++cnt == k)
					return j; // k번째 지우는 수 
			}
		}
	}

}
int main() {
	int n, k;
	// 입력 
	cin >> n >> k;
	
	// 연산 출력 
	cout << isPrime(n, k) << '\n';


}