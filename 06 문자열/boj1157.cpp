#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	int alph_arr[26] = { 0, };

	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] <= 'Z') {
			alph_arr[(int)word[i] - 65] += 1; 
		}
		else
			alph_arr[(int)word[i] - 97] += 1; 
	}

	int max = 0; char final;
	for (int i = 0; i < 26; i++) {
		if (max < alph_arr[i]) {
			max = alph_arr[i];
			final = i + 65;
		}
		else if (max == alph_arr[i]) {
			final = '?';
		}
	}

	cout << final;
}