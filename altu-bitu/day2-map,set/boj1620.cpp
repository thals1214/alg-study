// ���ϸ� ������ �̴ټ� 
#include <iostream>
#include <string>
#include <map>


using namespace std;

int main() {
	int N, M;
	string input;
	map<string, int> name; // �̸�->  ��ȣ
	map<int, string> number; // ��ȣ -> �̸�

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		name[input] = i; // key : name
		number[i] = input;  // key : number
	}

	while (M--) {
		cin >> input;
		if (isdigit(input[0])) // input -> number 
			cout << number[stoi(input)] << '\n'; // string to int
		else
			cout << name[input] << '\n';
	}

}
