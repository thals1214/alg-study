//
// Created by som k on 2022/07/23.
// https://www.acmicpc.net/problem/1946
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
vector<pair<int,int>> arr;

bool cmp(pair<int,int> &a1, pair<int,int> &a2){
    return a1.second < a2.second;
}

int calNumber(){
    int num = 1, temp, temp2;
    temp = arr[0].second;

    sort(arr.begin(), arr.end(), cmp);
    temp2 = arr[0].first;

    for(int i = 0; i< temp-1; i++){
        if(arr[i].first <= temp2){
            num++;
            temp2 = arr[i].first;
        }
    }
    return num;
}

int main(){
    int test, num;

    //입력
    cin>> test;
    while(test--){
        cin >> num;
        arr.assign(num,{0,0});

        for(int i = 0; i<num; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(),arr.end());

        //연산 및 출력
        cout << calNumber()<<'\n';
    }
}

