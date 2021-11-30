//
// Created by Somin on 2021/11/30.
// 1197 최소 스패닝 트리 -> https://www.acmicpc.net/problem/1197
//
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;
//Find 연산
int findParent(int node){
    if(parent[node] <0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) return false; //같은 집합에 있다면 사이클 발생
    if(parent[xp] < parent[yp]){ //새로운 루트 yp ->노드가 더 많이 존재한다면
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}
int kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq){
    int cnt = 0, sum = 0;
    //최소 스패닝 트리가 존재한다고 보장하기 때문에 while문으로 사용 가능
    while(cnt < v-1){
        int weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(unionInput(x,y)){
            cnt++;
            sum += weight;
        }
    }
    return sum;
}

int main(){
    int v, e, a, b, c;
    priority_queue<tp,vector<tp>,greater<>> pq;

    //입력
    cin >> v >> e;
    parent.assign(v+1,-1);
    while(e--){
        cin>>a >> b >>c;
        pq.push({c,a,b});
    }
    //연산&출력
    cout << kruskal(v,pq);

    return 0;
}
