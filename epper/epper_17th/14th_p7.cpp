/* low level*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> enlarge(int r, int c, int z_r, int z_c, vector<string> words) {
	vector<string> result;

	for (int i = 0; i < r; i++) {
		string temp = "";
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < z_c; k++) {
				temp += words[i][j];
			}
		}
		for (int m = 0; m < z_r; m++) {
			result.push_back(temp);
		}
	}
	return result;
}
int main() {
	int r, c, z_r, z_c;
	vector<string> words , result;
	string temp; 

	cin >> r >> c >> z_r >> z_c;
	for (int i = 0; i < r; i++) {
		cin >> temp;
		words.push_back(temp);
	}

	//for (auto iter : words) {
	//	cout << iter << '\n';
	//}

	result = enlarge(r, c, z_r, z_c, words);
	
	for (auto iter : result) {
		cout << iter << '\n';
	}
	
}