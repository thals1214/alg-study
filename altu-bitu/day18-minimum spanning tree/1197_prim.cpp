//
// Created by Somin on 2021/11/30.
// 1197 최소 스패닝 트리 -> https://www.acmicpc.net/problem/1197
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e6;
typedef pair<int,int> ci;

int prim(int v, int start, vector<vector<ci>> & graph){
    int sum = 0;
    vector<int> dist(v+1,INF);
    vector<bool> visited(v+1,false);
    priority_queue<ci, vector<ci>,greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue; //이미 방문했던 정점
        sum += weight;
        visited[node] = true;

        for(int i = 0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;

            if(!visited[next_node] && next_weight<dist[next_node]){
                dist[next_node] = next_weight;
                pq.push({next_weight,next_node});
            }
        }
    }
    return sum;
}

//그래프의 형태 볼 수 있음
int main(){
    int v, e, a, b, c;

    //입력
    cin >> v >> e;
    vector<vector<ci>> graph(v+1,vector<ci>(0));

    while(e--){
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }

    //연산&&출력
    cout << prim(v,1,graph);
}


