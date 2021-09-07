// 추월 
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	int N;
	string input;
	map<string, int>m; // key : string, value : int

	cin >> N;
	for (int i = 0; i < N; i++) { //들어가는 차들의 순서
		cin >> input;
		m[input] = i;
	}

	vector<int> seq; // 터널 에서 나온 차의 순서
	for (int i = 0; i < N; i++) {
		cin >> input;
		seq.push_back(m[input]); // 0부터 시작한 이유
	}

	int ans = 0; // 추월한 차들의 수
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (seq[i] > seq[j]) {
				ans++;
				continue;
			}
		}
	}

	cout << ans;

}