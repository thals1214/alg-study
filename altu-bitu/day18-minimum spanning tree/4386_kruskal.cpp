//
// Created by Somin on 2021/11/30.
// 4386 별자리 만들기 - https://www.acmicpc.net/problem/4386
//
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double,double> ci;
typedef tuple<double,int,int> tp;

vector<int> parent;

int findParent(int node){
    if(parent[node] <0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

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

//kruskal
double kruskal(int v, priority_queue<tp,vector<tp>,greater<>> & pq){
    int cnt = 0;
    double sum = 0;

    while(cnt <v-1){
        double weight = get<0>(pq.top());
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
    int n;
    priority_queue<tp, vector<tp>, greater<>> pq;

    cin >> n;
    parent.assign(n,-1);
    vector<ci>stars(n);
    for(int i = 0; i< n; i++)
        cin >> stars[i].first >> stars[i].second;

    //연산
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            double xd = stars[i].first - stars[j].first;
            double yd = stars[i].second - stars[j].second;
            pq.push({sqrt(xd*xd+yd*yd),i,j});
        }
    }
    cout <<fixed;
    cout.precision(2);
    cout << kruskal(n,pq);
}


