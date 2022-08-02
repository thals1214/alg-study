//
// Created by som k on 2022/08/01.
//
#include "iostream"
#include "vector"
#include "map"

using namespace std;

int main(){
    int n, num = 0;
    string s;
    map<string, int> arr1;  // string -> int
    vector<int> arr;

    //입력
    cin >> n;
    arr.assign(n,0);
    for(int i = 0; i< n; i++){
        cin >> s;
        arr1[s] = i;
    }

    for(int i = 0; i< n; i++){
        cin >> s;
        int key = arr1[s];
        arr[i] = key;
    }

    //연산
    for(int i = 0; i< n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                num++;
                break;
            }
        }
    }
    //출력
    cout << num;
}
