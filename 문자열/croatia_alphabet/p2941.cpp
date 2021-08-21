#include <iostream>
#include <string>

using namespace std;

int main() {
	string s; 
	int idx;
	cin >> s; 

	string arr[8] = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };
	
	for (int i = 0; i < 8; i++) {
		while (1) {
			idx = s.find(arr[i]);
			if (idx == string::npos)
				break;
			s.replace(idx, arr[i].length(), "#");
		}
	}
	cout << s.length();
}