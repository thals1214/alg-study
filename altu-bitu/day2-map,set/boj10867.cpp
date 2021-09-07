//중복빼고 정렬하기

#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, k;
	set<int> s;

	//입력
	cin >> N;
	while (N--) { // N으로 하기
		cin >> k;
		s.insert(k);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';


}