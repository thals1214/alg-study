/* average -but hard (dynamic programming) */

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b, int c) {
	return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

int solution(int n, vector<int> M)
{
	vector<int>  dp(n + 1, 0);
	dp[1] = M[0];
	if (n > 1) { dp[2] = M[0] + M[1]; }
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + M[i - 1], dp[i - 3] + M[i - 2] + M[i - 1]);
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;

	vector<int> M(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> M[i];
	}

	int ans = solution(n, M);
	cout << ans << endl;
	return 0;
}