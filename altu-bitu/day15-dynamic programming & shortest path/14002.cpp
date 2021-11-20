//
// Created by Somin on 2021/11/09.
// 가장 긴 증가하는 부분 수열4 - https://www.acmicpc.net/problem/14002
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> ci;

vector<int> back(int x, vector<int>& path){
    vector<int> result(0);
    while(x != -1){
        result.push_back(x);
        x = path[x];
    }
    return result;
}

ci lis(int n, vector<int>& arr, vector<int>& path){
    vector<int> dp(n+1,1); //자기 자신 포함하면 최소 lis 는 1이 되기 때문에 1로 초기화
    ci ans = {1,0}; //최장 길이, 마지막 원소 인덱스

    for(int i = 1; i<n; i++){
        int idx = -1; // 경로 저장 변수
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                //증가하는 관계,가장 큰 dp[j] + 1 을 찾아야
                dp[i] = dp[j] + 1;
                idx = j;
            }
        }
        path[i] = idx;
        if(ans.first < dp[i]) //최장 길이 + 마지막 원소 인덱스
            ans = {dp[i], i};
    }
    return ans;
}

int main(){
    int n;
    //입력
    cin >> n;
    vector<int> arr(n); //수열
    vector<int> path(n,-1);//경로 저장 배열

    for(int i = 0; i<n; i++)
        cin >> arr[i];

    //연산
    ci ans = lis(n,arr,path);
    vector<int> result = back(ans.second, path);

    //출력
    cout << ans.first << '\n';
    for(int i = result.size()-1; i>=0;i--){
        cout << arr[result[i]] <<' ';
    }

    return 0;
}

