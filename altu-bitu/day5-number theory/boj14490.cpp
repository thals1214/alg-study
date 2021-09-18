#include <iostream>
#include <string>

using namespace std;

// 재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b) {
	// 반복문 빠져나오기 
	if (b == 0) return a;
	gcdRecursion(b, a % b);
}
int main() {
	string s;

	// 입력 
	cin >> s;

	// 입력으로 받은 n,m 추출
	int index = s.find(':'); // :의 index 반환
	int n = stoi(s.substr(0, index)); //: 이전까지로 반환
	int m = stoi(s.substr(index + 1, s.length())); // s.length()까지로! 

	// 최대공약수 구하기 
	int g = gcdRecursion(max(m, n), min(m, n));

	cout << n / g << ':' << m / g << '\n';

}