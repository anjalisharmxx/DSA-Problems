class Solution {
public:
int fun(int index,vector<int>& cost,vector<int>& dp){
    if(index==0) return cost[0];
    if(index==1) return cost[1];

    if(dp[index]!=-1) return dp[index];
    int takeone=cost[index]+fun(index-1,cost,dp);
    int taketwo=cost[index]+fun(index-2,cost,dp);

    return dp[index]=min(takeone,taketwo);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(fun(n-1,cost,dp),fun(n-2,cost,dp));
    }
};