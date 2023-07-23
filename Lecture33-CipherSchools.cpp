#include "bits/stdc++.h"
using namespace std;


//Subset sum equal to K
int subsetsum(int curr,int currsum,vector<int> &arr,int sum,vector<vector<int>> &dp){
    if(currsum==sum){
        return 1;
    }
    if(curr>=arr.size()){
        return 0;
    }
    if(currsum>sum){
        return 0;
    }
    if(dp[curr][currsum]!=-1){
        return dp[curr][currsum];
    }
    int pick = subsetsum(curr+1,currsum+arr[curr],arr,sum,dp);
    int unpick = subsetsum(curr+1,currsum,arr,sum,dp);

    dp[curr][currsum] = pick+unpick;
    return dp[curr][currsum];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return subsetsum(0,0,arr,k,dp);
}



// Rod cutting problem
int rod(vector<int> prices,int n,int dp[]){
    if(n<=0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

    int ans = INT_MIN;
    for (int i = 0; i < n;i++){
        int cut = i + 1;
        int current_ans =  prices[i]+rod(prices,n-cut,dp);

        ans = max(ans, current_ans);
    }
    dp[n]=ans;
    return dp[n];
}

int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}