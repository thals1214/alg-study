#include <iostream>

using namespace std;

int gcdBad(int a, int b) {
	// 두 수중에 더 작은 걸 기준으로 하나씩 감소 하여 공약수 판단
	for (int i = min(a, b); i > 1; i--) {
		// 공약수가 존재한다면 바로 리턴
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 1; // 끝까지 없다면 최대공약수는 1 
}

// 재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b) {
	// 종료조건
	if (b == 0) {
		return a; // b가 0이면 a가 최대 공약수 가 됨 
	}
	// a% b 구한 후 b와 자리를 바꾸어서 호출 
	return gcdRecursion(b, a % b);
}

int main() {
	int a, b;

	cin >> a >> b;

	//// calculate O(n)방식 
	//int g = gcdBad(a, b); // O(n)
	//int l = (a * b) / g; // 최소 공배수 

	// 유클리드 호제법을 통한 최대공약수 
	int g = gcdRecursion(max(a, b), min(a, b)); 
	int l = (a * b) / g; // 최소 공배수 
}