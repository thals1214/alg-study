#include <iostream>
#include <string>

using namespace std;
// a = 97

int main2() {
	string S;
	int alphabet_arr[26];
	cin >> S;

	for (int i = 0; i < 26; i++) {
		alphabet_arr[i] = -1;
	}

	for (int i = 0; i < S.length(); i++) {
		if (alphabet_arr[(int)S[i] - 97] < 0) alphabet_arr[(int)S[i] - 97] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet_arr[i] << " ";
	}
	
	return 0;
}