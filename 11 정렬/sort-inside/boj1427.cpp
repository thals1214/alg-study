#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, i = 0;
	cin >> N;
	int arr[10] = {0,};
	vector <int> sorted_arr;

	// N이 한자리 수 일 경우 
	int num = N;
	if (num < 10) {
		cout << num;
		return 0;
	}

	while (num / 10 != 0) {
		arr[i] = num % 10;
		num = num / 10;
		i++;
		if (num / 10 == 0) arr[i] = num % 10;
	}
	
	for (int j = 0; j <= i; j++) {
		sorted_arr.push_back(arr[j]);
	}
	
	sort(sorted_arr.begin(), sorted_arr.end());

	for (int j = i; j >= 0; j--) {
		cout << sorted_arr[j];
	}
	
}