#include <iostream>

int main() {
	int arr[42] = { 0 };
	int user_input, temp, total_number = 0;

	for (int i = 0; i < 10; i++) {
		std::cin >> user_input;
		arr[user_input % 42] ++;
	}

	for (int i = 0; i < 42; i++) {
		if (arr[i] > 0) total_number++;
	}

	std::cout << total_number;



}