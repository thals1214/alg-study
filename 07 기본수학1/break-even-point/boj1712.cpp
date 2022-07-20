#include <iostream>
using namespace std;

int main() {
	unsigned int a, b, c;
	cin >> a >> b >> c;

	int i = 0;
	if (b >= c) cout << -1;
	else
		cout << (a / (c - b)) + 1;
	
}