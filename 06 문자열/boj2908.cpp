#include <iostream>
#include <string>

using namespace std;

int main() {

	int num1, num2;
	cin >> num1 >> num2;

	num1 = (num1 / 100) + 10 * ((num1 % 100) / 10) + 100 * ((num1 % 100) % 10);
	num2 = (num2 / 100) + 10 * ((num2 % 100) / 10) + 100 * ((num2 % 100) % 10);

	if (num1 > num2) cout << num1;
	else
		cout << num2;
}