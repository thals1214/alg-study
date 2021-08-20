#include <iostream>

void d() {
	int temp, temp2, new_num, i;
	int arr[10001] = { 0 };

	for (i = 1; i <= 10000; i++) {
		if (i < 100) {
			new_num = i + i % 10 + i / 10;
			arr[new_num] = 1;
		}
		else if (i < 1000) {
			temp = i % 100;
			new_num = i + i / 100 + temp / 10 + temp % 10;
			arr[new_num] = 1;
		}
		else if (i < 10000) {
			temp = i % 1000;
			temp2 = temp % 100;
			new_num = i + i / 1000 + temp / 100 + temp2 / 10 + temp % 10;
			if(new_num<= 10000) arr[new_num] = 1;
		}
	}

	for (i = 1; i <= 10000; i++) {
		if (arr[i] != 1)
			std::cout << i << "\n";
	}
}

int main() {
	d();
}