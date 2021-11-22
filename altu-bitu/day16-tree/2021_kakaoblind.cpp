//
// Created by Somin on 2021/11/16.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

vector<vector<int>> makeTree(int n, vector<vector<int>>& links){
    vector<vector<int>> tree(n,vector<int>(0));
    for(int i = 0; i<links.size();i++){
        tree[links[i][0]].push_back(links[i][1]);
    }
    return tree;
}

int fillDp(vector<int> &sales, vector<vector<int>> &tree, int node, bool flag){
    if(dp[node][flag] != -1)
        return dp[node][flag];

    if(tree[node].empty())
        return dp[node][flag] = flag ? sales[node-1] : 0;
    dp[node][flag] = 0; //초기화
    bool attend_flag = false; //부하직원 중 한명이라도 참석
    int diff = 1e9 * 2; //참석, 불참 매출하락 정도의 차이가 가장 작은 값
    for(int i = 0; i<tree[node].size();i++){
        int next_node = tree[node][i];
        int attend = fillDp(sales,tree,next_node,true);
        int absent = fillDp(sales,tree,next_node,false);

        dp[node][flag] += min(attend,absent);
        if(attend < absent)
            attend_flag = true;
        diff = min(diff,attend-absent); //모든 팀원이 불참했을때 대비
    }
    if(flag)
        return dp[node][flag] += sales[node-1];
    if(attend_flag)
        return dp[node][flag] += diff;
    return dp[node][flag];
}

int solution(vector<int> sales, vector<vector<int>> links){
    int ans = 0;
    int v = sales.size();
    dp.assign(v+1,vector<int>(2,-1));
    vector<vector<int>> tree = makeTree(v+1,links);

    ans = min(fillDp(sales,tree,1,true),fillDp(sales,tree,1,false));
    return ans;
}
