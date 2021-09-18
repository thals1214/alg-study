#include <iostream>
#include <vector>
#define max(x,y) (x)>(y) ? (x):(y)

using namespace std;

long long solution(int n, vector<vector<long long>> money) {
	long long ans;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) money[i][j] += money[i - 1][0];
			else if (j == i) money[i][j] += money[i - 1][j - 1];
			else
				money[i][j] += max(money[i - 1][j - 1], money[i - 1][j]);
		}
	}
	ans = money[n - 1][0];
	for (int j = 0; j <= n; j++) {
		ans = max(money[n - 1][j], ans);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<long long>> money;

	for (int i = 0; i < n; i++) {
		money.push_back(vector<long long>(i + 1, 0));
		for (int j = 0; j <= i; j++) {
			cin >> money[i][j];
		}
	}
	cout << solution(n, money) << '\n';
	return 0;

}