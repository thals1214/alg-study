#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

// ��ȣ�� ¦�� ������ �� �̿��ϱ�
map<char, char> bracket;

// ��ȣ�� ������ �̷���� Ȯ��
bool isBalance(string input) {
	stack<char> s;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(' || input[i] == '[')
			s.push(input[i]);
		else if (input[i] == ')') {
			if (s.empty() || s.top() != '(')
				return false;
			s.pop();
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() != '[')
				return false;
			s.pop();
		}
	}
	return s.empty(); // empty�� ��쿡�� true! 
	
}
int main() {
	string input;

	while (true) {
		getline(cin, input); // ���� ���� �ޱ�
		if (input == ".")
			break;

		// input �� ���� ��ȣ �´��� Ȯ��
		if (isBalance(input))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}


}