#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

// 괄호의 짝을 저장할 맵 이용하기
map<char, char> bracket;

// 괄호가 균형을 이뤘는지 확인
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
	return s.empty(); // empty일 경우에만 true! 
	
}
int main() {
	string input;

	while (true) {
		getline(cin, input); // 띄어쓰기 포함 받기
		if (input == ".")
			break;

		// input 에 대해 괄호 맞는지 확인
		if (isBalance(input))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}


}