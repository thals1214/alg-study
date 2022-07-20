#include <iostream>

int main() {
	int input_num, max, min, temp;
	std::cin >> input_num;

	std::cin >> temp;
	max = temp;
	min = temp;

	for (int i = 1; i < input_num; i++) {
		std::cin >> temp;
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}

	std::cout << min << " " << max;
}