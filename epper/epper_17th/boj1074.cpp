/* average */

#include <iostream>
#include <cstdio>

int solution(int n, int r, int c) {
	int ans = 0; // 방문수 

	int x = 1 << (n - 1); // x = 2^ (n-1) shift 연산자 
	int y = x;

	while (n-- > 0) {
		int temp = 1 << (n - 1); // 현재 사분면의 길이 /2 
		int skip = 1 << 2 * n; // 방문했다고 가정하는 수의 크기 

		if (r < y && c < x) {
			// 1사분면
			x -= temp;
			y -= temp;
		}
		else if (r < y && c >= x) {
			// 2사분면
			ans += skip;
			x += temp;
			y -= temp;
		}
		else if (r >= y && c < x) {
			// 3사분면 
			ans += skip * 2;
			x -= temp;
			y += temp;
		}
		else {
			// 4사분면
			ans += skip * 3;
			x += temp;
			y += temp;
		}
	}
	return ans;
}

int main() {
	int n, r, c;
	scanf_s("%d %d %d", &n, &r, &c);
	printf("%d", solution(n, r, c));
	return 0;
}