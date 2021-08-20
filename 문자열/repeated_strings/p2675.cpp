#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int test_case, repeat_num; 
	
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> repeat_num >> s;

		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < repeat_num; k++) {
				cout << s[j];
			}
		}
		cout << "\n";
	}
}