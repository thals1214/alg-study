/* gold */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
우선순위 큐 (최소 힙)에는 가장 큰 수 부터 N번째 큰 수까지 총 N개의 숫자가 들어있음
가장 큰 수 부터 N번째 큰수까지를 최소 heap에 넣었기 때문에 root에 있는 값은 N번째 큰 수가 되게 됨
*/
int main() {
	// 입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, input;
	priority_queue<int, vector<int>, greater<>> pq; // 최소 힙 , 정렬이랑 반대
	 
	cin >> n;
	int size = n * n;
	while (size--) {
		cin >> input;

		if (pq.size() < n)
			pq.push(input);

		else if (pq.top() < input) {
			pq.pop();
			pq.push(input);
		}
	}
	// 출력
	cout << pq.top();
}