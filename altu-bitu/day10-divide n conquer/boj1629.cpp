//곱셈
#include <iostream>

using namespace std;
typedef long long ll;

//분할 정복으로 곱셈 하는 함수
ll divide(int a, int b, int c) {
	//Conquer: B가 1인가
	if (b == 1) return a % c;

	//divide부터 : 제곱수 나누기
	if (b % 2 == 0) { //b가 짝수일때 
		ll sub_problem = divide(a, b / 2, c);
		return (sub_problem * sub_problem) % c;
	}

	//b가 홀수 일때 
	return (a * divide(a, b - 1, c)) % c;
}

int main() {
	//입력
	int a, b, c;
	cin >> a >> b >> c; // scope: max value of int 

	//연산
	cout << divide(a, b, c);

}