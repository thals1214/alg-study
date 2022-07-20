//
// Created by som k on 2022/07/20.
//
#include "iostream"

using namespace std;

int main(){
    int n;
    string b, s;
    //입력
    cin >> n;

    //연산
    for(int i = 1; i<=n; i++){
        for(int j = n-i; j>0; j--){
            cout << ' ';
        }
        for(int j = i; j>0; j--){
            cout << '*';
        }
        cout <<'\n';
    }
}