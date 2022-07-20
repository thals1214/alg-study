
#include <iostream>

int main() {
	int user_input;
	int num1, num2;

	std::cin >> user_input;

	while (user_input > 0) {
		std::cin >> num1 >> num2;
		std::cout << num1 + num2 << std::endl;
		user_input--;
	}

}