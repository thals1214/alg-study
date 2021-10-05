//행렬 제곱
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;
const int MOD = 1000;

matrix a; 

//Combine :행렬 곱 결과 리턴

matrix combine(int n, matrix m1, matrix m2) {
	matrix result(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				result[i][j] += (m1[i][k] * m2[k][j]); // 최댓값: 5 * 1000 * 1000 -> INT 
			result[i][j] %= MOD;
		}
	}
	return result;
}

//Divide 
matrix divide(int n, long long b){
	//COnquer : B가 1인가?
	if (b == 1) return a;

	//Divide :제곱수 나누기
	if (b % 2 == 0) { //b가 짝수 일때 
		matrix sub_problem = divide(n, b / 2);
		return combine(n,sub_problem,sub_problem);
	}
	//b가 홀수 일때
	return combine(n,a,divide(n,b-1));
}
int main() {
	int n; //행렬 크기
	long long b; //1000억까지

	//입력
	cin >> n >> b;
	a.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	//연산
	matrix ans = divide(n, b);

	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] % MOD << ' '; //반례 2 1 1000 1000 1000 1000
		}
		cout << '\n';
	}
}