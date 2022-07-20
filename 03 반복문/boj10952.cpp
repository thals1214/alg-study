#include <iostream>

int main() {
	int input1, input2;

	while (true) {
		std::cin >> input1 >> input2;
		if (input1 == 0 && input2 == 0) {
			break;
		}
		std::cout << input1 + input2 << "\n";

	}
}