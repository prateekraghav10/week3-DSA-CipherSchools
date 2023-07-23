#include "bits/stdc++.h"
using namespace std;


// LIS
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=1;
    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i] && dp[i]<dp[j]){
                dp[i]=dp[j];
            }
        }
        dp[i]++;
        ans=max(ans,dp[i]);
    }
    return ans;
}


//LPS
int longestPalindromeSubseq(string s1) {
    string s2 = s1;
    reverse(s1.begin(),s1.end());
    int n = s1.length(),i,j;
    vector<vector<int>> dp(n+1,vector<int> (n+2,0));
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}