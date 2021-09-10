/* 카드 */

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	int n;
	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//연산
	while (q.size() != 1) {
		// 위에 있는 카드 버리기
		q.pop();
		// 위에 있는 카드 아래로 옮기기
		int card = q.front();
		q.pop();
		q.push(card);
	}

	// 출력
	cout << q.front();
}