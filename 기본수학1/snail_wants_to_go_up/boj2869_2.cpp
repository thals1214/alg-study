#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int height = 0;
	int num = V / (A - B);

	if (V % (A - B) == 0) {
		height = (num - 1) * (A - B) + A;
	}
}