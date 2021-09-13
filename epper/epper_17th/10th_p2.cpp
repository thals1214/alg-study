/* low */
#include <iostream>

using namespace std;

int main() {
	string input;
	int total = 0, score = 0; 
	bool flag = true;

	cin >> input; 

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'O') {
			if (flag) {
				score += 1;
				flag = true;
			}
			else {
				score = 1;
				flag = true; 
			}
			total += score;
		}
		else {
			flag = false;
			score = 0;
		}
	}
	cout << total;

}
