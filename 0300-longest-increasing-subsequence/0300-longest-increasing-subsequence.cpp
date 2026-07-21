class Solution {
public:
    int solve(int i,int prevv,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        
        if(dp[i][prevv+1]!=-1) return dp[i][prevv+1];
        int len=0+solve(i+1,prevv,nums,dp);
        if(prevv==-1 || nums[i]>nums[prevv]){
             len=max(len,1+solve(i+1,i,nums,dp));
        }

        return dp[i][prevv+1]=len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};