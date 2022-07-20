#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	int start = 666, temp;
	while (cnt != N) {
		temp = start;
		do {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		} while (temp > 0);

		if (cnt == N) {
			cout << start;
		}
		start++;
	}
}