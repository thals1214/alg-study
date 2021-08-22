#include <iostream>

using namespace std;
int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int height = 0;
	int cnt = 0;
	while (true) {
		height += A - B;
		if (height < V) {
			cnt += 1;
			if (height + A == V) {
				cout << cnt + 1;
				return 0;
			}
		}
		else {
			break;
		}
	}
	cout << cnt + 1;

}