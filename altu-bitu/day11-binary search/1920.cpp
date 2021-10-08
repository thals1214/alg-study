//수 찾기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

//이분 탐색
bool lowerBound(int left, int right, int target) {

	while (left <= right) { // left가 right 포이터보다 뒤에 있으면 break
		int mid = (left + right) / 2;
		if (arr[mid] == target)
			return true;
		if (arr[mid] > target)
			right = mid - 1;
		if (arr[mid] < target)
			left = mid + 1;
	}
	return false; //target 못찾음 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, input;
	
	//입력
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산
	sort(arr.begin(), arr.end());
	
	cin >> m;
	while (m--) {
		cin >> input;
		//연산 & 출력
		cout << lowerBound(0, n - 1, input) << '\n';
		//cout << binary_search(arr.begin(), arr.end(), input) <<'\n'; //원소의 존재만 알려줌 -> 직접 구현하는 법 알아야 함
	}

	return 0;
}