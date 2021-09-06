#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] < 'D') cnt += 3;
		else if (s[i] < 'G') cnt += 4;
		else if (s[i] < 'J') cnt += 5;
		else if (s[i] < 'M') cnt += 6;
		else if (s[i] < 'P') cnt += 7;
		else if (s[i] < 'T') cnt += 8;
		else if (s[i] < 'W') cnt += 9;
		else
			cnt += 10;
	}
	cout << cnt;
}