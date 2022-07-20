#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int M, N;
	bool flag = true;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		flag = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			if (i == 1) continue;
			cout << i << "\n";
		}
	}
}