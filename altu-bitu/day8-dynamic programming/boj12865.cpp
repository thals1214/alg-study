//배낭
#include <iostream>
#include <vector>

using namespace std;

struct info {
	int w, v; //weight & value
};

//2차원 dp사용 
int knapsack_2(int n, int k, vector<info>& product) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); //2차원 배열 선언

	for (int i = 1; i <= n; i++) { //각 물품에 대해, i: 물품 번호, j: 최대 배낭 무게
		for (int j = 1; j < product[i].w; j++) //우선 해당 물품을 배낭에 넣을 수 없는 경우
			dp[i][j] = dp[i - 1][j]; //그 전 물품에 대한 현재 무게의 최댓값 저장
		for (int j = product[i].w; j <= k; j++) //해당 물품을 배낭에 넣는게 가능한 경우
			dp[i][j] = max(dp[i - 1][j - product[i].w] + product[i].v, dp[i - 1][j]); //배낭에 넣는 경우와 안 넣는 경우 중 최댓값 저장
	}
	return dp[n][k];
}

//1차원 dp사용
int knapsack_1(int n, int k, vector<info>& product) {
	vector<int> dp(k + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= product[i].w; j--) {
			dp[j] = max(dp[j - product[i].w] + product[i].v, dp[j]);//j: 최대 배낭 무게, 1차원이니 무게 k부터 시작(거꾸로)

		}
	}
	return dp[k];
}
int main() {
	int n, k;

	//입력
	cin >> n >> k;
	vector<info> product(n + 1, { 0,0 }); //vector초기화 
	for (int i = 1; i <= n; i++)
		cin >> product[i].w >> product[i].v;

	//연산+출력
	cout << knapsack_2(n, k, product) << '\n'; // 2차원 벡터 이용
//	cout << knpasack_1(n, k, product) << '\n'; // 1차원 벡터 이용 
}