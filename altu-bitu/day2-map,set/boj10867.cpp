//�ߺ����� �����ϱ�

#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, k;
	set<int> s;

	//�Է�
	cin >> N;
	while (N--) { // N���� �ϱ�
		cin >> k;
		s.insert(k);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';


}