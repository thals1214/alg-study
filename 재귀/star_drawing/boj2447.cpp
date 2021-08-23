#include <iostream>

using namespace std;

void draw_star(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << " ";
	}
	else {
		if(n == 1) { // can also be written like -> if(n / 3 ==0) 
			cout << "*";
		}
		else {
			draw_star(i, j, n / 3);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			draw_star(i, j, n);
		}
		cout << "\n";
	}

}