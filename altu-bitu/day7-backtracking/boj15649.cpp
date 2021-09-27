#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
int num[SIZE];
bool check[SIZE + 1];

// 재귀함수로 구현한 백트래킹
void backtrackg(int cnt) { // cnt : 수열의 인덱스 
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			num[cnt] = i; // 수열에 값 저장 
			check[i] = true; // 수사용
			backtrackg(cnt + 1); // 다음 수열 인덱스 호출 
			check[i] = false; // 원래 상태로 돌려놓음 
		}
		
	}
}
int main() {
	// n과 m 전문제 풀어보면서 감 기르는것 추천
	// 1<= n,m <= 8

	
	cin >> n >> m;

	// 연산 + 출력
	backtrackg(0);


}