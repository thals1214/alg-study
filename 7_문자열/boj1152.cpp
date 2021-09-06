#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;
	getline(cin, sentence); 

	int cnt = 0;
	bool space = false;

	if (sentence.empty()) {
		cout << "0";
		return 0;
	}
	cnt = 1;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ')
			cnt++;
	}
	if (sentence[0] == ' ')
		cnt--;
	if (sentence[sentence.length() - 1] == ' ')
		cnt--;

	cout << cnt;
	return 0;

}