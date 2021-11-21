//
// Created by Somin on 2021/11/16.
// 1991 트리순회 - https://www.acmicpc.net/problem/1991
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, pair<char,char>> tree;

//전위
void preorder(char node){
    if(node == '.')
        return;
    cout <<node;
    preorder(tree[node].first);
    preorder(tree[node].second);
}
//중위
void inorder(char node){
    if(node == '.')
        return;
    inorder(tree[node].first);
    cout <<node;
    inorder(tree[node].second);
}

//후위
void postorder(char node){
    if(node == '.')
        return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    cout <<node;

}

int main(){
    int n;
    int root, left, right;

    //입력
    cin >> n;
    while(n--){
        cin >>root >> left >> right;
        tree[root] = make_pair(left,right);
    }

    //연산 && 출력
    preorder('A');
    cout <<'\n';
    inorder('A');
    cout <<'\n';
    postorder('A');
    return 0;
}

