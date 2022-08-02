//
// Created by som k on 2022/08/01.
// https://www.acmicpc.net/problem/1764
//

#include "iostream"
#include "set"
#include "vector"
#include "algorithm"

using namespace std;

int main(){
    int n, m, cnt = 0;
    string input;
    set<string> arr;
    vector<string> sorted_arr;

    //입력
    cin >> n >> m;
    while(n--){
        cin >> input;
        arr.insert(input);
    }
    while(m--){
        cin >> input;
        if(arr.find(input) != arr.end()){
            cnt++;
            sorted_arr.push_back(input);
        }
    }
    //연산 및 출력
    sort(sorted_arr.begin(),sorted_arr.end());
    cout << cnt <<'\n';
    for(auto iter = sorted_arr.begin(); iter != sorted_arr.end(); iter++){
        cout << *iter << '\n';
    }
}
