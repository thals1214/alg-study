#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int i = 0;
	if (N == 1) {
		cout << 1;
		return 0;
	}

	while (true) {
		if (N > (i * i * 3 - 3 * i + 1) && N <= (i * i * 3 + 3 * i + 1)) {
			cout << i + 1;
			break;
		}
		else {
			i += 1;
		}
	}
}