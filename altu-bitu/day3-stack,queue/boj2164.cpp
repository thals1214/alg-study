/* ī�� */

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	int n;
	// �Է�
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//����
	while (q.size() != 1) {
		// ���� �ִ� ī�� ������
		q.pop();
		// ���� �ִ� ī�� �Ʒ��� �ű��
		int card = q.front();
		q.pop();
		q.push(card);
	}

	// ���
	cout << q.front();
}