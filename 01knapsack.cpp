#include<bits/stdc++.h>
using namespace std ;

int knapsack01(vector<int>wt,vector<int>profit,int w,int indx,vector<vector<int>>&dp){
    if(indx< 0 ){
        return 0 ;
    }
    if(dp[indx][w]!=-1)return dp[indx][w] ;

    // 3 conditions
    // 1.wecannot take current weight weight[indx] > w 
    if(wt[indx]>w){
        dp[indx][w] = knapsack01(wt,profit,w,indx-1,dp) ;
    }
    else{
        //2.take or 3. not take 

        dp[indx][w] = max(profit[indx] + knapsack01(wt,profit,w-wt[indx],indx-1,dp),knapsack01(wt,profit,w,indx-1,dp)) ;
    }
    return dp[indx][w] ;
    

}

int main(){
    vector<int> profit = { 60, 100, 120 };
    vector<int>weight = { 10, 20, 30 };
    int W = 50;
   vector<vector<int>>dp(profit.size(),vector<int>(W+1,-1)) ;
    cout << knapsack01(weight, profit,W,2,dp);
    return 0 ;
}
