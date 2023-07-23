#include "bits/stdc++.h"
using namespace std;


//Coin Change I
int conchange(int curr,int n,vector<int> &coins,int amount, vector<vector<int>> &dp){
    if(amount==0){
        return 0;
    }
    if(curr==n || amount<0){
        return 100000;
    }
    if(dp[curr][amount]!=-1){
        return dp[curr][amount];
    }
    int pick=1+conchange(curr,n,coins,amount-coins[curr],dp);
    int unpick=conchange(curr+1,n,coins,amount,dp);
    return dp[curr][amount]=min(pick,unpick);


}
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
    int ans=conchange(0,n,coins,amount,dp);
    if(ans==100000){
        return -1;
    }
    return ans;
}


//Coin change II
int coinchange(int curr,int curramount,int amount,vector<int> &coins,vector<vector<int>> &dp){
    if(curr>=coins.size()){
        return 0;
    }
    if(curramount>amount){
        return 0;
    }
    if(curramount==amount){
        return 1;
    }
    if(dp[curr][curramount]!=-1){
        return dp[curr][curramount];
    }
    int pick = coinchange(curr,curramount+coins[curr],amount,coins,dp);
    int unpick = coinchange(curr+1,curramount,amount,coins,dp);

    dp[curr][curramount] = pick+unpick;
    return dp[curr][curramount];
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
    return coinchange(0,0,amount,coins,dp);
}

int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}