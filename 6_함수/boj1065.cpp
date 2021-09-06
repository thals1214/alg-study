#include <iostream>

void sequence(int i) {
	int sum = 0;
	if (i < 100) {
		std::cout << i << "\n";
	}
	else if (i <= 1000) {
		sum += 99;
		for (int j = 100; j <= i; j++) {
			if (j / 100 - (j % 100) / 10 == (j % 100) / 10 - (j % 100) % 10)
				sum++;
		}
		std::cout << sum << "\n";
	}

}

int main() {
	int user_input;
	std::cin >> user_input;

	sequence(user_input);
}