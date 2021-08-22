#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << "1/1";
		return 0;
	}
	int i = 1;
	int temp, temp2;

	while (true) {
		if (N > ((i * i + i) / 2) && N <= (i * i + 3 * i + 2)/2) {
			if (i % 2 == 0) {
				temp = N - ((i * i + i) / 2);
				temp2 = i + 2 - temp;
				cout << temp2;
				cout << "/";
				cout << temp;
				return 0;
			}
			else {
				temp = N - ((i * i + i) / 2);
				temp2 = i + 2 - temp;
				cout << temp;
				cout << "/";
				cout << temp2;
				return 0;
			}
		}
		i++;
	}
}