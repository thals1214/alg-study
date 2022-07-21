//
// Created by som k on 2022/07/21.
//
#include "iostream"
#include "vector"

using namespace std;
vector<int> arr;

void bubbleSort(){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i ; j < n-i; j++){
            if(arr[j] < arr[j-1]){
                // swap
                int tmp = arr[j-1];
//                arr[j-1]= arr[j];
//                arr[j] = tmp;
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

void bubbleSortAdv(){
    int n = arr.size();
    for(int i = 0; i< n; i++){
        bool flag = true;
        for(int j = 1; j<n-i; j++){
            if(arr[j-1] > arr[j]){
                flag = false;
                swap(arr[j], arr[j-1]);
            }
        }
        if(flag)
            break;
    }
}

int main(){
    int n;

    //입력
    cin >> n;
    arr.assign(n,0);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    //연산
//    bubbleSort();
    bubbleSortAdv();

    //출력
    for(int i = 0; i<n; i++){
        cout << arr[i] <<'\n';
    }


}