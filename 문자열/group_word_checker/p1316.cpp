#include <iostream>
#include <string>

using namespace std;
int main() {
	string str; int user_input;
	char temp;
	int cnt = 0, int idx;
	bool flag = true;
	cin >> user_input;

	for (int i = 0; i < user_input; i++) {
		cin >> str;
		temp = str[0];
		for (int j = 1; j < str.length(); j++) {
			if (j != temp) {
				flag = false;
				idx = str.find(temp);
				if (idx == string::npos)
					continue;
				temp = str[j];
			}
		}
		
	}

}