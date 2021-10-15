//
// Created by somin on 10/15/2021.
// Tomato https://www.acmicpc.net/problem/7576
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> ci;

int bfs(int n, int m, int cnt, vector<vector<int>> &matrix, queue<ci> q){
    int dx[4] = {-1,1,0,0}; // 상 하 좌 우
    int dy[4] = {0,0,-1,1};

    int t = 0; //시간 저장
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second; //현재 행 과 열
        q.pop();
        t = matrix[cr][cc]; //현재 탐색까지 걸린 시간
        cnt--; //익은 토마토의 개수 감소
        for(int i = 0; i<4; i++){ //상하좌우 방향 탐색(인접 노드 탐색)
            int nr = cr + dx[i]; //방문하려는 노드
            int nc = cc + dy[i];
            if(nr > 0 && nr <= n && nc > 0 && nc <= m &&matrix[nr][nc] == 0){
                //범위 체크 주의하기
                matrix[nr][nc] = matrix[cr][cc] + 1; //하루가 지나면 인접한 토마토들은 익는다 (->시간 증가값을 저장한다)
                q.push(ci(nr,nc));
            }
        }
    }
    if(!cnt) //모든 토마토가 익었다면
        return t-1;
    //아니라면
    return -1;
}

/*
 * 최소/ 최단 -> BFS 활용
 */

int main(){
    queue<ci> q; //bfs 탐색을 위한 토마토 위치 저장
    int n, m;

    //입력
    cin >> m >> n;  //열이 먼저 들어옴
    int cnt = n*m; // 전체 토마토의 개수 (탐색 종료 조건에 활용)
    vector<vector<int>> matrix(n+1,vector<int>(m+1,0)); // (1.1)부터 시작

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1)
                q.push(ci(i,j)); //익은 토마토 바로 삽입 (시작 노드)
            else if(matrix[i][j] == -1)
                cnt--;

        }
    }

    //연산과 출력
    cout << bfs(n,m,cnt,matrix,q);

    return 0;
}

