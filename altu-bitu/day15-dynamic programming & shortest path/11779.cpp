//
// Created by Somin on 2021/11/09.
// 최소비용 구하기2 - https://www.acmicpc.net/problem/11779
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ci;
const int INF = 1e8;

//역추적
vector<int> back(int x, vector<int>& path){
    // x: 도착정점부터
    vector<int> result(0);
    while(x != 0){
        result.push_back(x);
        x= path[x];
    }
    return result;
}
int dijkstra(int n, int s, int e, vector<vector<ci>>& graph, vector<int>& path){
    vector<int> dist(n+1,INF);
    priority_queue<ci,vector<ci>, greater<>> pq;

    //시작 위치 초기화
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight> dist[node]) // 이미 탐색한 노드 (없으면 시간초과)
            continue;

        for(int i = 0; i<graph[node].size();i++){
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second;
            if(dist[next_node] > next_weight){ //더 짧은 경로
                dist[next_node] = next_weight;
                path[next_node] = node;
                pq.push({next_weight,next_node});
            }
        }
    }
    return dist[e];
}
int main(){
    int n,m,a,b,c,s,e;

    cin >> n>> m;
    vector<vector<ci>> graph(n+1,vector<ci>(0));
    vector<int> path(n+1,0);//경로 저장
    while(m--){
        cin >> a >> b>> c;
        graph[a].push_back({b,c});
    }
    cin >> s >> e;

    int ans = dijkstra(n,s,e,graph,path);
    vector<int> result = back(e,path);

    // 출력
    cout << ans << '\n' << result.size() << '\n';
    for(int i = result.size()-1; i>= 0; i--){
        cout <<result[i] << ' ';
    }

    return 0;

}

