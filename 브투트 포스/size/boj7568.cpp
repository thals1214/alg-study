#include <iostream>
using namespace std;

int main() {
	int N;
	int weight[50] = { 0, };
	int height[50] = { 0, };
	int total[50] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i] >> height[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if ((weight[i] < weight[j]) && (height[i] < height[j])) {
				total[i]++;
			}
		}
		total[i]++;
	}

	for (int i = 0; i < N; i++) {
		cout << total[i] << " ";
	}
	
}