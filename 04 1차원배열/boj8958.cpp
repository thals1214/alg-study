#include <iostream>

int main() {
	int num_of_test, score = 0, total_score = 0;
	char arr[80];
	std::cin >> num_of_test;

	for (int i = 0; i < num_of_test; i++) {
		std::cin >> arr;

		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				score++;
				total_score += score;
			}
			else {
				score = 0;
			}
		}
		std::cout << total_score << "\n";
		score = 0;
		total_score = 0;

	}
}