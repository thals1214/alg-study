//공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;

//가장 인접한 두 공유기 사이의 최대 거리가 dist이도록 공유기를 설치했을때, 설치된 공유기의 개수
int router(int dist) {
	//첫번쨰 집에 무조건 공유기를 설치
	int cnt = 1;
	int pos = house[0];

	for (int i = 0; i < house.size(); i++) {
		if (house[i] - pos < dist) continue; // 가장 가까운 집과의 거리가 dist이상이여야 설치 가능
		// i번째 집에 공유기 설치
		cnt++;
		pos = house[i];
	}
	return cnt;
}

//가능한 최대 거리 중 가장 큰 값 = upper bound -> Parametric Search 이용
int upperSearch(int left, int right, int target) {
	int ans = 0;
	while (left <= right) {
		//가장 인접한 두 공유기 사이의 거리가 mid일 때 공유기를 최대 몇개 사용할 수 있을까 
		int mid = (left + right) / 2;
		int installed = router(mid);

		if (installed < target) //mid의 거리로는 target만큼의 공유기를 설치 할 수 없음 -> 거리 줄여야 
			right = mid - 1;
		else if (installed > -target) { //mid의 거리로는 taret만큼의 공유기를 설치 할 수 있음 -> 거리 늘려야
			ans = mid; // 현재의 mid값 저장 최종 갱신 값은 upper bound
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, c;

	//입력
	cin >> n >> c;
	house.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> house[i];

	//연산
	sort(house.begin(), house.end());

	//연산 & 출력
	cout << upperSearch(1, house[n - 1] - house[0], c);
}