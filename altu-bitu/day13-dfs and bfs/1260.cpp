//
// Created by somin on 10/15/2021.
// DFS and BFS https://www.acmicpc.net/problem/1260
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_matrix;
vector<vector<bool>> adj_list;

vector<bool> visited_recur;

//DFS : 재귀함수로 구현
void dfsRecur(int v){
    if(visited_recur[v]) //이미 방문한 노드라면
        return;

    visited_recur[v] = true;
    cout << v <<' ';

    for(int i = 0; i<adj_list[v].size();i++){
        dfsRecur(adj_list[v][i]);
    }
}

vector<int> dfs(int n, int v){
    stack<int> st;
    vector<bool> visited(n+1,false);
    vector<int> result; //탐색순으로 노드 저장

    st.push(v); //처음 탐색 노드 삽입
    visited[v] = true; //방문체크
    result.push_back(v);

    //탐색 시작
    while(!st.empty()){
        int node = st.top(); //탐색하려는 노드
        bool check = false; // 자식 노드 존재 여부
        // st.pop();
        //인접행렬로 검사
        for(int i = 1; i<= n; i++){
            if(adj_matrix[node][i] && !visited[i]){//정점 연결 & 처음 방문
                check = true; //자식 노드 존재 한다는 표시
                visited[i] = true;
                st.push(i);
                result.push_back(i); //탐색 노드 바로 삽입
                break; // 이 문제에서는 작은 노드부터 방문해야하기 때문에
            }
        }
        //인접 리스트로 검사
        for(int i = 0; i<adj_list[node].size();i++){
            if(!visited[adj_list[node][i]]){
                check = true;
                visited[adj_list[node][i]]  = true;
                st.push(adj_list[node][i]);
                result.push_back((adj_list[node][i]));
                break;
            }
        }
        if(!check) st.pop(); //자식 노드가 없다면 pop
    }
    return result;

}

vector<int> bfs(int n, int v){
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<int> result;

    q.push(v);
    visited[v] = true;

    //탐색 시작
    while(!q.empty()){
        int node = q.front(); // 현재 탐색하려는 노드
        q.pop();
        result.push_back(node);
        //인접행렬로 검사
        for(int i = 1; <= n; i++){
            if(adj_matrix[node][i] && !visited[i]){
                visited[i] = true;
                q.push(i); //앞으로 탐색해야할 노드이므로 큐에 삽입
            }
        }
        //인접리스트로 검사
        for(int i = 0; i<adj_list[node].size();i++){
            if(!visited[adj_list[node][i]]){
                visited(adj_list[node][i])  = true;
                q.push(adj_list[node][i]);
            }
        }
    }
    return result;
}


/*
 * 방문할 수 있는 정점이 여러개 -> 작은 것부터 방문
 */

int main(){
    int n, m ,v, a, b;
    vector<vector<int>> result(2,vector<int>());

    //입력
    cin >> n>> m>>v;
    adj_matrix.assign(n+1,vector<bool>(n+1,false));
    adj_list.assign(n+1,vector<int>());
    while(m--){
        cin >> a >>b;
        //인접행렬
        adj_matrix[a][b] = adj_matrix[b][a];
        //인접리스트
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    //인접리스트 구현시, 노드 번호가 작은것부터 방문하기 위해 정렬
    for(int i = 1; i<= n; i++)
        sort(adj_list[i].begin(),adj_list[i].end());

    //DFS - stack
    result[0] = dfs(n,v);

    //DFS - 재귀함수
    visited_recur.assign(n+1,false);
    dfsRecur(v);

    //BFS - queue
    result[1] = bfs(n,v);

    //출력
    for(int i = 0; i<2; i++){
        for(int j = 0; j<result[i].size();j++){
            cout << result[i][j] << ' ';
        }
        cout <<'\n';
    }
    return 0;
}


