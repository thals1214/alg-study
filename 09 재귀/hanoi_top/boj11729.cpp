#include <iostream>
using namespace std;

// dividing the problem -> A->B / B->C for N-1 disks
int hanoi(int n) {
	if (n == 1) return 1;
	return 2 * hanoi(n - 1) + 1;
}

void hanoi_tower(int n, int from, int temp, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		
	}
	else {
		hanoi_tower(n - 1, from, to, temp);
		cout << from << " " << to << "\n";
		hanoi_tower(n - 1, temp, from, to);
	}

}

int main() {
	int n;
	cin >> n;

	int num = hanoi(n);
	cout << num << "\n";
	hanoi_tower(n, 1, 2, 3);
}