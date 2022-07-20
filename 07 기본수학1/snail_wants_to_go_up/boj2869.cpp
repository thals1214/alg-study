#include <iostream>
using namespace std;
// time error
int main2() {
	int A, B, V;
	cin >> A >> B >> V;

	int height = 0, cnt = 0;
	while (height <= V) {
		cnt++;
		height += A - B;

		if (height + B >= V) {
			cout << cnt;
			return 0;
		}
	}
	cout << cnt;
}