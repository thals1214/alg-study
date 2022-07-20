//
// Created by som k on 2022/07/20.
//
#include <iostream>

using namespace std;

int main(){
    // 입력
    int hour, minute, length;
    int res_hour, res_min, hour_var;

    cin >> hour >> minute ;
    cin >> length;

    // 연산
    res_min = (minute + length) % 60;
    hour_var = (minute + length) / 60;

    if (hour_var){
        res_hour = (hour + hour_var) % 24;
    }
    else{
        res_hour = hour;
    }

    // 출력
    cout << res_hour << ' ' << res_min;

}