#include <iostream>

using namespace std;

int main() {
	int user_input;
	int H, W, N; // height, width, N
	int num1, num2; // 
	int tens, ones, room_number;

	cin >> user_input;
	for (int i = 0; i < user_input; i++) {
		cin >> H >> W >> N;
		num1 = N / H;
		num2 = N % H;
		if (num2 == 0) {
			ones = num1;
			tens = H - num2;
			room_number = tens * 100 + ones;
		}
		else {
			ones = num1 + 1;
			tens = num2;
			room_number = tens * 100 + ones;
		}
		cout << room_number << "\n";
	}
}