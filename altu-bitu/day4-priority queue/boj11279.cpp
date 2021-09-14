/* heap 구현하기 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> heap_vec;

// empty
bool empty() {
	return heap_vec.size() == 1;
}

// push
void push(int num) {
	int idx = heap_vec.size(); // 1의 위치부터 들어가니까 
	heap_vec.push_back(num);
	/* 종료조건
	 idx == 1
	 더이상 올라갈 필요가 없을때 -> 부모노드가 나보다 우선순위 높음
	*/
	// root = 1에 도달하거나, 더이상 상위노드의 값이 크지 않다면 반복문 탈출
	while (idx != 1 && heap_vec[idx] > heap_vec[idx / 2]) {
		swap(heap_vec[idx], heap_vec[idx / 2]);
		idx /= 2; // 상위 노드로 이동
	}
}

// pop 
int pop() {
	int item = heap_vec[1]; // 0이 아니라 1임 (1부터 시작!)
	swap(heap_vec[1], heap_vec[heap_vec.size() - 1]); 
	heap_vec.pop_back(); // data 제거
	
	int parent = 1, child = 2;
	// 만약 오른쪽 하위노드가 존재하면 값을 비교, 상위 노드와 비교 (갱신)
	while (child < heap_vec.size()) {
		if (child + 1 < heap_vec.size() && heap_vec[child] < heap_vec[child + 1])
			child++;
		if (heap_vec[parent] >= heap_vec[child]) // 더이상 내려갈 필요 없음
			break;
		swap(heap_vec[parent], heap_vec[child]); // 상위노드 하위노드 바꿔줌
		parent = child;
		child = parent * 2;
	}
	return item;
}

int main() {
	// 입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	priority_queue<int> pq;
	heap_vec.push_back(0); // 인덱스가 1부터 시작하도록

	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			// pop
			if (empty()) cout << 0 << '\n';
			else
				cout << pop() << '\n';
			continue;
		}
		if (x != 0) {
			// push
			push(x);
			continue;
		}
	}
}