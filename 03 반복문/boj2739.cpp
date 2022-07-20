//
// Created by som k on 2022/07/20.
// https://www.acmicpc.net/problem/2739
//

#include "iostream"

using namespace std;

int main(){
    int n;
    //입력
    cin >> n;

    //연산 && 출력
    for(int i = 1; i<= 9; i++){
        cout << n << " * "<< i << " = " << n*i << '\n';
    }
}