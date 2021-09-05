#include <iostream>
#include <vector>

using namespace std;

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);


	return val;
}

int main() {
	int a, b, c;
	int result;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
			
	}
}