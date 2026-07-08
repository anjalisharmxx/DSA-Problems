class Solution {
public:
int fun(int index,vector<int>& coins,int amount,vector<vector<int>>& dp){
    if (amount == 0) return 1;
    if(index==0){
        if(amount%coins[index]==0) return 1;
        
        return 0;
    }

    if(dp[index][amount]!=-1) return dp[index][amount];

    int nottake=fun(index-1,coins,amount,dp);
    int take=0;
    if(coins[index]<=amount){ 
        take = fun(index,coins,amount-coins[index],dp);

    }

    return dp[index][amount]= take+nottake;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return fun(n-1,coins,amount,dp);
    }
};