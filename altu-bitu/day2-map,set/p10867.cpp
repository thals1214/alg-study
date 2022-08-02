//
// Created by som k on 2022/07/24.
//https://www.acmicpc.net/problem/10867
//

#include "iostream"
#include "set"

using namespace std;

int main(){
    int n, num;
    set<int> arr;

    //입력
    cin>> n;
    while(n--){
        cin >> num;
        arr.insert(num);
    }

    //출력
    for(auto iter = arr.begin(); iter != arr.end(); iter++){
        cout << *iter <<' ';
    }

}