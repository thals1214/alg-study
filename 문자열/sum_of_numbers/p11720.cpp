#include <iostream>

int main() {
	int user_number, sum = 0;
	char user_input;

	std::cin >> user_number;
	for (int i = 0; i < user_number; i++) {
		std::cin >> user_input;
		sum += user_input-'0'; //value in form of ascii -> subtract '0' (48)
	}

	std::cout << sum << std::endl;

}