#include <iostream>

int main() {
	int user_input;
	std::cin >> user_input;

	for (int i = 1; i <= user_input; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}