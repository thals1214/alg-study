#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int arr[26] = {0,}; // alphabet array 
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if ((int)(s[i]) <= 90) {
			arr[(int)s[i] - 65]++; // LargeText 
		}
		else
			arr[(int)s[i] - 97]++; // SmallText 
	}

	char max = -1, flag;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			flag = i +65;
		}
		else if (arr[i] == max) {
			flag = '?';
		}
	}
	cout << flag << endl;

}