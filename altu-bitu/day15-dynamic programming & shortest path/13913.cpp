//
// Created by Somin on 2021/11/09.
// 숨박꼭질 4 - https://www.acmicpc.net/problem/13913
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;

//역추적
vector<int> back(int x, vector<int>& path){
    //x: k(도착지점부터)
    vector<int> result(0);
    while(x!= -1){
        result.push_back(x);
        x = path[x]; // 다음 정점
    }
    return result;
}

int bfs(int n, int k,vector<int>& path){
    vector<int> check(SIZE+1,0);
    queue<int> q;
    int ans = 0;

    check[n] = 1;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == k){
            //동생을 찾으면 탐색 종료
            ans = check[x] - 1; //시작 노드 초기화를 1로 했기 때문에 (1은 방문체크 때문)
            break;
        }
        vector<int> child = {x-1, x+1, x*2};
        for(int i = 0; i<3; i++){
            if(child[i]>=0 && child[i] <= SIZE && !check[child[i]]){
                check[child[i]] = check[x] + 1;
                path[child[i]] = x;
                q.push(child[i]);
            }
        }
    }
    return ans;

}
int main(){
    int n, k;
    vector<int> path(SIZE+1,-1);
    //입력
    cin >> n >> k;

    //연산
    int ans = bfs(n,k,path);
    vector<int> res = back(k,path);
    //출력
    cout << ans <<'\n';
    for(int i = res.size()-1 ; i>=0; i--){
        cout << res[i] << ' ';
    }

    return 0;
}