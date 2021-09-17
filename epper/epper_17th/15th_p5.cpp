/* average level */
#include <iostream>

using namespace std;
string solution(string s) {
	int cnt = 0;
	string ans = "";
	if (s[0] == '1') ans.push_back('1');
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != s[i + 1]) {
			ans.push_back('A' + cnt);
			cnt = 0;
		}
		else cnt++;
	}
	ans.push_back('A' + cnt); 
	return ans;
}

int main() {
	string s;
	cin >> s;

	string ans = solution(s);
	cout << ans;
	
}