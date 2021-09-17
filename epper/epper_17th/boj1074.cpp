/* average */

#include <iostream>
#include <cstdio>

int solution(int n, int r, int c) {
	int ans = 0; // �湮�� 

	int x = 1 << (n - 1); // x = 2^ (n-1) shift ������ 
	int y = x;

	while (n-- > 0) {
		int temp = 1 << (n - 1); // ���� ��и��� ���� /2 
		int skip = 1 << 2 * n; // �湮�ߴٰ� �����ϴ� ���� ũ�� 

		if (r < y && c < x) {
			// 1��и�
			x -= temp;
			y -= temp;
		}
		else if (r < y && c >= x) {
			// 2��и�
			ans += skip;
			x += temp;
			y -= temp;
		}
		else if (r >= y && c < x) {
			// 3��и� 
			ans += skip * 2;
			x -= temp;
			y += temp;
		}
		else {
			// 4��и�
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