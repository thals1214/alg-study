#include <iostream>
#include <string>

using namespace std;

// n번째 종말의 숫자 리턴
int endnumber(int n) {
	int cnt = 0; 
	// 첫번째 종말의 숫자 (666)부터 차례로 검사하기 
	for (int i = 666;; i++) {
		string s = to_string(i); //stoi (문자->숫자)
		if (s.find("666") != s.npos) // 어디에 있는지 위치 반환 
			cnt++;
		if (cnt == n) return i; // n번째 종말의 숫자 
	}
}

int main() {
	int n;

	cin >> n;

	cout << endnumber(n) << '\n';
}