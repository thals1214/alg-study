//
// Created by som k on 2022/07/20.
//
#include "iostream"

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t,a,b;
    // 입력
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << a+b << '\n';
    }
    return 0;
}