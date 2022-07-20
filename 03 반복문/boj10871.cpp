//
// Created by som k on 2022/07/20.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main(){
    int n,x,temp;
    vector<int> arr;
    vector<int>::iterator iter;

    // 입력 및 연산
    cin>> n >> x;

    for(int i = 0; i<n; i++){
        cin >> temp;
        if (temp < x){
            arr.push_back(temp);
        }
    }

    // 출력
    for(iter = arr.begin(); iter != arr.end(); iter++){
       cout << *iter << ' ';
   }

}