//
// Created by Somin on 2021/11/25.
//
#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

int main(){
    vector<vector<int>> a(SIZE,vector<int>(SIZE,0));
    vector<vector<int>> b(SIZE,vector<int>(SIZE,0));
    vector<vector<int>> c(SIZE,vector<int>(SIZE,0));

    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            a[i][j] = j*1;
            b[i][j] = i*j + 2;
            c[i][j] = j - i*2;
        }
    }

    for(int i = 0; i<SIZE;i++){
        for(int j = 0; j<SIZE; j++){
            int sum = 0;
            for(int k = 0; k<SIZE; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cout << a[i][j] <<' ';
        }
        cout <<'\n';
    }
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cout << b[i][j] <<' ';
        }
        cout <<'\n';
    }
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cout << c[i][j] <<' ';
        }
        cout <<'\n';
    }
}

