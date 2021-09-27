#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64;

// (row.col) 에서 시작하는 8*8 체스판 만드는데 드는 최소 카운트 리턴 
// B로 시작하는 체스판을 기준으로 계산한 후 W로 시작하는 체스판 만드 바꾸는 칸 수는 64에서 빼서 계산 

int 
int main() {
	int n, m;
	int ans = SIZE + 1; // 정답은 체스판 칸 개수 +1로 초기화 

	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));  // 초기화 행: n 열: m 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			int cnt = ;// 시작 인덱스 가 (i,j)인 체스판 만드는 최소값 
			ans = min(cnt, ans);
		}
	}

	cout << ans << '\n';

	return 0;

}