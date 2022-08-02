//
// Created by som k on 2022/08/01.
// https://www.acmicpc.net/problem/2015
//

#include "iostream"
#include "vector"
#include "map"

using namespace std;
typedef long long ll;

int main(){
    vector<int> num, s;
    map<int, ll> m; // key: s[x] -> S[i] - k 의 값, value: x의 개수
    int n, k;
    ll ans = 0;

    // 입력
    cin >> n >> k;
    num.assign(n+1, 0);
    s.assign(n+1,0);
    for(int i = 1; i<= n; i++){
        cin >> num[i];
        s[i] = num[i] + s[i-1];
    }

    for(int i = 1; i<= n; i++){
        cout << s[i] << ' ';
    }
    cout << '\n';

    //연산
    for(int i = 1; i<= n; i++){
        if(s[i] == k) ans++;
        ans += m[s[i]-k]; //S[x] = S[i] - k 를 만족하는 x의 개수만큼 ans 증가
        m[s[i]]++; //항상 x < i 이여야 하므로 i번째 검사 후 S[i]를 맵에 저장, 이미 존재하면 value 값 증가

        // dubug
        cout << i << '\n';
        for(auto iter = m.begin(); iter != m.end(); iter++){
            cout << iter->first << ' ' << iter->second <<'\n';
        }
        cout << "ans : " << ans << '\n';
    }

    //출력
    cout << ans << '\n';
    return 0;
}
