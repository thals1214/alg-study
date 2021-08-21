#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	int count = 0; 
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			flag = true;
		}
		else if (flag) {
			flag = false;
			count++;
		}
	}
	cout << count;
	return 0;
}