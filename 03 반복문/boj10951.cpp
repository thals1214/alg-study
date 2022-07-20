#include <iostream>

int main() {
	int user_input1, user_input2;

	while (std::cin >> user_input1 >> user_input2) {
		std::cout << user_input1 + user_input2 << std::endl;
	}
}