#include <iostream>
#include <string>

using namespace std;
int main() {
	string str; int user_input;
	cin >> user_input;
	int cnt = 0;

	for (int i = 0; i < user_input; i++) {
		cin >> str;
		int arr[26] = { 0, };
		int flag = 0;
		for (int j = 0; j < str.length(); j++) {
			arr[(int)str[j] - 97]++;
			if (arr[(int)str[j] - 97] > 1 && str[j] != str[j - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) cnt++;
	}
	cout << cnt;

}