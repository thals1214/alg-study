/* low */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, b, c;
	long long cnt = 0;
	vector<int> arr;

	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		temp -= b;
		cnt++;
		if (temp <= 0) continue;
		cnt  += (temp / c);
		if (temp % c > 0) cnt++;
	}

	cout << cnt << '\n';
}