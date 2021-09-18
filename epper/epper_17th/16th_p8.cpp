/* lv high */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int table[100001];
long long solution(int n, vector<int> goal) {
	long long ans = 0; 
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (goal[j] > goal[i])
				ans++;
		}
	}
	return ans;
}