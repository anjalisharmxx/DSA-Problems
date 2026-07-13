class Solution {
public:
    int solve(int i,vector<int>& cost,vector<int>& dp){
        if(i==0) return cost[0];
        if(i==1) return cost[1];

        if(dp[i]!=-1) return dp[i];

        int onestep=cost[i]+solve(i-1,cost,dp);
        int twostep=cost[i]+solve(i-2,cost,dp);

        return dp[i]=min(onestep,twostep);
    } 
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};