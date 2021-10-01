//동전 
#include <iostream>
#include <vector>

using namespace std;

int coinCnt(int n, int k, vector<int>& coin) {
	int cnt = 0; //필요한 동전 개수
	for (int i = n - 1; i >= 0; i--) {
		//i:동전 idx, 큰 동전부터 사용
		if (k == 0) //원하는 가치 합을 다 만든 경우
			break;
		if (coin[i] <= k) {
			cnt += k / coin[i];
			k = k % coin[i]; //남은 가치 값
		}
	}
	return cnt;
}

int main() {
	int n, k;

	//입력
	cin >> n >> k;
	vector<int> coin(n, 0);
	for (int i = 0; i < n; i++) cin >> coin[i];

	//연산 & 출력
	cout << coinCnt(n, k, coin);
	return 0;
}