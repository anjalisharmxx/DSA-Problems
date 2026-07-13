class Solution {
public:
    int sol(int i,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int nott=0+sol(i-1,coins,amount,dp);
        int take=1e9;
        if(coins[i]<=amount) take=1+sol(i,coins,amount-coins[i],dp);

        return dp[i][amount]=min(take,nott);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=sol(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};