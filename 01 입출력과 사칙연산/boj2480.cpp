//
// Created by som k on 2022/07/20.
// https://www.acmicpc.net/problem/2480
//
#include "iostream"

using namespace std;

// 같은눈 3개 -> 10000 + 같은눈 * 1000
// 같은눈 2개 -> 1000 + 같은눈 * 100
// 가장 큰 눈 * 100

int main(){
    int a,b,c;
    int result;

    // 입력
    cin >> a >> b >> c;

    // 연산
    if(a == b){
        if(b == c){ //a = b = c
            result = 10000 + a * 1000;
        }
        else{ // a = b != c
            result = 1000 + a*100;
        }
    }
    else if(b == c){ // a != b = c
        result = 1000 + b * 100;
    }
    else if (a == c){ // a = c != b
        result = 1000 + a * 100;
    }
    else{
        int temp = max(a,b);
        result = 100 * max(c,temp);
    }

    // 출력
    cout << result;
    return 0;


}