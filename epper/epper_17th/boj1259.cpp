/* low */
#include <iostream>

using namespace std;

void calFelindrome(int n) {
	int original_input = n , reversed_input = 0;
	
	while (n > 0) {
		reversed_input = reversed_input * 10 + n % 10;
		n /= 10;
	}
	if (reversed_input == original_input) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		calFelindrome(n);
	}
}