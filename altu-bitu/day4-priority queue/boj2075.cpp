/* gold */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
�켱���� ť (�ּ� ��)���� ���� ū �� ���� N��° ū ������ �� N���� ���ڰ� �������
���� ū �� ���� N��° ū�������� �ּ� heap�� �־��� ������ root�� �ִ� ���� N��° ū ���� �ǰ� ��
*/
int main() {
	// ����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, input;
	priority_queue<int, vector<int>, greater<>> pq; // �ּ� �� , �����̶� �ݴ�
	 
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
	// ���
	cout << pq.top();
}