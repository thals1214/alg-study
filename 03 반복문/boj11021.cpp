//
// Created by som k on 2022/07/20.
// https://www.acmicpc.net/problem/11021
//

#include "iostream"

using namespace std;

int main(){
    int n,a,b;

    // 입력 및 출력
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> a >> b;
        cout << "Case #" <<i <<": " << a+b << '\n';
    }
}
