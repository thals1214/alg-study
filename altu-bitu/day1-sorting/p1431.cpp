//
// Created by som k on 2022/07/22.
// https://www.acmicpc.net/problem/1431
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int sumNum(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])) //문자(char)에 대해 숫자인지 판별해줌
            sum += str[i] - '0'; // char -> int로 바꾸는 방법 (ascii 코드 참고)
    }
    return sum;
}

bool cmp(const string &p1, const string &p2){
    if(p1.length() != p2.length()) //길이 다르다면 짧은 순
        return p1.length() <p2.length();

    if(sumNum(p1) != sumNum(p2))
        return sumNum(p1) < sumNum(p2);
    // 알파벳부터 비교
    return p1 < p2; //사전 순

}

int main(){
    int n;
    vector<string> arr;

    //입력
    cin >> n;
    arr.assign(n,"");

    for(int i = 0; i<n ;i++){
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(),arr.end(),cmp);

    //출력
    for(int i = 0; i<n ;i++){
        cout <<arr[i] <<'\n';
    }

}
