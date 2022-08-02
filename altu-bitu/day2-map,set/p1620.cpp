//
// Created by som k on 2022/08/01.
// https://www.acmicpc.net/problem/1620
//

#include "iostream"
#include "map"

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    string s, q;
    map<string, int> arr1;
    map<int, string> arr2;

    //입력
    cin >> n >> m ;
    for(int i = 1; i<=n; i++){
        cin >> s;
        arr1.insert({s,i});
        arr2.insert({i,s});
    }

    //연산 및 출력
    for(int i = 0; i< m; i++){
        cin >> q;
        if(isdigit(q[0])){ //정수라면
            cout << arr2[stoi(q)] << '\n';
        }
        else{
            cout << arr1[q] << '\n';
        }
    }
}