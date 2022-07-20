#include <iostream>

int main() {
	int user_input, flag = -1, cycle = 0;
	int tens, ones, new_num, original_num;

	std::cin >> user_input;
	original_num = user_input;

	while (user_input != flag) {
		tens = original_num / 10;
		ones = original_num % 10;
		new_num = (tens + ones) % 10;

		flag = ones * 10 + new_num;
		original_num = flag;
		cycle++;
	}

	std::cout << cycle;
}