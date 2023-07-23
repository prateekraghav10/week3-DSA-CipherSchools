#include "bits/stdc++.h"
using namespace std;

//Nth Fibonacci Number
int fibb(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fibb(n-1,dp)+fibb(n-2,dp);
    return dp[n];
}
int fib(int n) {
    vector<int> dp(n+1,-1);
    return fibb(n,dp);
}

//Power(X,N)
int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;
    return x * power(x, n - 1);
}


//NCR
int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}