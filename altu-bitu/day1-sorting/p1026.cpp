//
// Created by som k on 2022/07/22.
// https://www.acmicpc.net/problem/1026
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool comp(int a1, int a2){
    return a1 > a2;
}

int main(){
    int n, res = 0;
    vector<int> a,b;

    // 입력
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);

    for(int i = 0; i<n; i++){
        cin >>a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    //연산
    sort(a.begin(),a.end(), comp); //내림차순
    sort(b.begin(),b.end());

    for(int i = 0; i<n; i++){
        res += a[i] * b[i];
    }

    cout << res ;

}
