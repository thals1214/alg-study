//
// Created by som k on 2022/07/21.
// https://www.acmicpc.net/problem/10825
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct info{
    string name;
    int kor, eng, math;
};

bool cmp(const info &i1, const info &i2){
    if(i1.kor != i2.kor) // 감소하는 순서
        return i1.kor > i2.kor;
    if(i1.eng != i2.eng) // 증가하는 순서
        return i1.eng < i2.eng;
    if(i1.math != i2.math)
        return i1.math > i2.math;
    return i1.name < i2.name;
}
int main(){
    int n;
    vector<info> arr;

    //입력
    cin >> n;
    arr.assign(n,{});
    for(int i = 0; i< n; i++){
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
    }

    //연산
    sort(arr.begin(),arr.end(),cmp);

    //출력
    for(int i = 0; i<n; i++){
        cout << arr[i].name <<'\n';
    }

}
