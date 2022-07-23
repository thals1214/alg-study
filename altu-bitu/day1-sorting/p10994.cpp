//
// Created by som k on 2022/07/23.
//https://www.acmicpc.net/problem/10994
//

#include "iostream"
#include "vector"

using namespace std;

void drawStar(vector<vector<char>> &star, int width,int row,int col){
    if(width == 1){
        star[row][col] = '*';
        return;
    }
    drawStar(star, width - 4, row +2, col + 2);

    for(int i = row; i< row+width; i++){
        star[i][col] =  star[row][i] = star[row+width-1][i] = star[i][width+col-1] = '*';
    }

}
int main(){
    int n, width;

    //입력
    cin >> n;
    width = 4*n-3;
    vector<vector<char>> star(width,vector<char>(width,' '));

    //연산
    drawStar(star,width,0,0);

    //출력
    for(int i = 0; i<width; i++){
        for(int j = 0; j<width; j++){
            cout << star[i][j];
        }
        cout <<'\n';
    }

    return 0;
}
