//색종이 만들기
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper; 
//pair 말고 vector 사용 -> idx로 사용 

//Conquer: 부분 종이가 모두 같은 색인가? 
bool conquer(int size, int row, int col, int color) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[i + row][j + col] != color) return false; //색이 다른 종이가 없다면
		}
	}
	return true;
}
//색종이를 나누는 함수 (Divide)
vector<int> divide(int size, int row, int col) {
	vector<int> combine = { 0,0 };

	//Conquer
	if (conquer(size,row,col,paper[row][col])) {
		combine[paper[row][col]]++;
		return combine;
	}

	//Divide :색종이 4등분하기
	int sub_size = size / 2; //4등분 한 색종이 한변의 길이
	// (0,0) (0,ss) (ss,0) (ss,ss)
	for (int i = 0; i <= sub_size; i += sub_size) {
		for (int j = 0; j <= sub_size; j += sub_size) {
			vector<int> sub_problem = divide(sub_size, row + i, col + j);

			//Combine: 색종이의 개수 세기
			combine[0] += sub_problem[0];
			combine[1] += sub_problem[1];
		}
	}
	return combine;
}

int main() {
	int n;

	//입력
	cin >> n;
	paper.assign(n,vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}
	//연산
	vector<int> ans = divide(n, 0, 0);

	//출력
	cout << ans[0] << '\n' << ans[1];
	
}