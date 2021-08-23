#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int M, N, min, cnt = 0, sum = 0;
	bool flag = true;
	cin >> M;
	cin >> N;


	for (int i = M; i <= N; i++) {
		flag = true;  // initialize 
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
			sum += i;
			if (i == 1) {
				cnt--;
				sum--;
			}
			if (cnt == 1) min = i;
		}
	}
	if (cnt == 0) {
		cout << -1 << "\n";;
	}
	else {
		cout << sum << "\n";
		cout << min << "\n";;
	}

}