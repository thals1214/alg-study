//체육복 
#include <string>
#include <vector>

using namespace std;
/*
* 학생의 체육복 개수 표시
* 왼쪽 학생부터 양 옆의 학생에게 체육복을 빌릴 수 있을지 검사
* 마지막으로 1개 이상 학생 개수 세주기
* 
* 왼쪽학생한테 먼저 빌리는 이유 
* -> 그 다음번 학생의 선택지 감소 
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> student(n + 1, 1);
	int answer = 0;

	for (int i = 0; i < lost.size(); i++) 
		student[lost[i]]--;
	for (int i = 0; i < reserve.size(); i++)
		student[reserve[i]]++;

	for (int i = 1; i <= n; i++) { // 1번학생부터 그리디적으로 양 옆으로 체육복 빌릴 수 있으면 빌리기
		if (student[i]) continue; // 체육복 있다면
		if (student[i - 1] == 2) {//왼쪽학생한테 체육복 빌리기
			student[i - 1]--;
			student[i]++;
		}
		else if (student[i + 1] == 2) {//오른쪽학생한테 빌리기
			student[i + 1]--;
			student[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (student[i])//체육복 있다면 
			answer++;
	}
	
	return answer;
}