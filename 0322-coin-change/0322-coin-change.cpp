class Solution {
public:
    int fun(int index,vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[0]==0) return amount / coins[0];

            return 1e9;
        }

        if(dp[index][amount]!=-1) return dp[index][amount];

        int nottake=0+fun(index-1,coins,amount,dp);
        int take=1e9;
        if(coins[index]<=amount) take=1+fun(index,coins,amount-coins[index],dp);

        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=fun(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};