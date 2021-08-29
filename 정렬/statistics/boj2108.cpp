#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // to use round() function

using namespace std;

int main() {
	int num, sum = 0, temp;
	vector<int> arr; // arr to sort out numbers
	int arr2[8001] = {0,}; // arr to count same values 
	
	cin >> num; // get total number

	for (int i = 0; i < num; i++) {
		cin >> temp;
		sum += temp;
		arr.push_back(temp);
		arr2[temp + 4000]++; 
	}

	sort(arr.begin(), arr.end());

	// 산술평균 출력 - 소수점 이하 첫째 자리에서 반올림
	sum = round((float)sum / num);
	cout << sum <<"\n";

	// 중앙값 출력
	temp = num / 2;
	cout << arr[temp] <<"\n";

	// 최빈값 출력
	int max = 0, index; 
	bool flag = false;

	for (int i = 0; i < 8001; i++) {
		if (arr2[i] > max) {
			flag = false;
			max = arr2[i];
			index = i;
		}
		else if (arr2[i] == max) {
			flag = true;
		}
	}

	int idx = 0;
	if (flag == false) { cout << index - 4000 << "\n"; }
	else {
		for (int i = 0; i < 8001; i++) {
			if (arr2[i] == max) {
				idx++;
			}
			if (idx == 2) {
				index = i;
				break;
			}
		}
		cout << index - 4000 << "\n";
	}

	// 범위 출력 (max-min)
	temp = arr.back() - arr.front(); // max number - min number
	cout << temp << "\n";


}