#include <iostream>

int main() {
	int a, b, c, i;
	int result;

	int arr[10] = { 0 };

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	result = a * b * c;

	while (result > 0) {
		i = result % 10;
		arr[i]++;
		result /= 10;
	}

	for (int j = 0; j < 10; j++) {
		std::cout << arr[j] << "\n";
	}


}