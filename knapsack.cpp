#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int> w, vector<int> val, int n, int W, vector<vector<int>>& dp){
    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(w[n-1] > W){
        return dp[n][W] = knapsack(w, val, n-1, W, dp);
    }

    return dp[n][W] = max((knapsack(w, val, n-1, W, dp)) , val[n-1] + knapsack(w,val,n-1, W - w[n-1], dp));
    
}

int main(){
    int n,W;
    cin>>n>>W;
    vector<int> w(n);
    vector<int> val(n);

    for(int i = 0;i<n; i++){
        cin>>w[i]>>val[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
    int ans = knapsack(w,val, n,W, dp);
    cout<<ans<<endl;
}
