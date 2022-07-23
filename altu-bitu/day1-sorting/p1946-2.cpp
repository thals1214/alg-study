//
// Created by som k on 2022/07/23.
// different, better solution
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> ci; //pair<int,int>를 ci라고 정의

int cntEmploy(int n, vector<ci> rank){
    int ans = 1, first_rank = rank[0].second;

    for(int i = 1; i< n; i++){
        if(first_rank > rank[i].second){
            // 가장 높은 면접심사 순위 계속 갱신하여 O(n)으로 풀이
            first_rank = rank[i].second;
            ans++ ;
        }
    }
    return ans;
}

int main(){
    int t, n, ans;
    vector<ci> rank;

    //입력
    cin >> t;
    while(t--){
        cin >> n;
        rank.assign(n,ci(0,0));

        for(int i = 0 ; i< n; i++){
            cin >> rank[i].first >>rank[i].second ;

            sort(rank.begin(),rank.end());
            cout << cntEmploy(n,rank);
        }
    }
}