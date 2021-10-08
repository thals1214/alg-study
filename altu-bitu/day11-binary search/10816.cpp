//숫자카드 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

//lower bound
int lowerBound(int left, int right, int target) {

	while (left <= right) { // left가 right 포이터보다 뒤에 있으면 break
		int mid = (left + right) / 2;
		//중간값이 target보다 크다면 target은 왼쪽에 있음
		//중간값이 target과 같다면, 왼쪽에 target과 같은 값이 더 있을 수 있음
		if (arr[mid] >= target)
			right = mid - 1;
		if (arr[mid] < target)
			left = mid + 1;
	}
	/*
	* right + 1 return하는 이유
	* right가 움직일 때는 arr[mid]값이 target이상일 때
	* 값이 target 이상이면서 index가 가장 작은 mid값이 lower bound
	* right는 mid - 1이므로 right + 1은 lower bound가 됨
	*/

	return right + 1; //break됬을 때 맨 마지막으로 갱신된 값
}

//upper bound
int upperBound(int left, int right, int target) {
	while (left <= right) { // left가 right 포이터보다 뒤에 있으면 break
		int mid = (left + right) / 2;

		if (arr[mid] > target)
			right = mid - 1;
		//중간값이 target보다 작으면 target은 오른쪽에 있음
		//중간값이 target과 같다면 오른쪽에 더 같은 값들이 있을 수 있음 
		if (arr[mid] <= target)
			left = mid + 1;
	}
	return right+1; //target 못찾음 

	/*
	* right + 1을 리턴하는 이유
	* left가 옮겨가기 때문에 break가 일어남
	* break전에 left와 right는 같은 곳 가르킴
	* 이 상태에서 right(mid)가 가르키는 값은 target 이하기 때문에 left포인터가 이동하고 break
	* 이떄의 left값은 target을 처음으로 초과하는 upper bound이며 
	* 직전에 left와 right의 위치가 같았으므로 right + 1이 upper bound이 됨
	* 
	* ** left 리턴해도 됨
	*/
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
		cout << upperBound(0, n - 1, input) - lowerBound(0, n - 1, input) << ' ';
		//cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(),arr.end(),input); //  upper_bound - arr.begin()하면 됨
 	}
}