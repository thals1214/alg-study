#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int user_num;
	int input[100] = { 0, };
	int cnt = 0; bool flag = true;

	cin >> user_num;
	
	for (int i = 0; i < user_num; i++) {
		cin >> input[i];
		if (input[i] == 1) cnt--;
	}

	for (int i = 0; i < user_num; i++) {
		flag = true;
		for (int j = 2; j <= sqrt(input[i]); j++){
			if (input[i] % j == 0){
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
		}
	}
	cout << cnt;
}