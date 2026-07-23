class Solution {
public:
    bool solve(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        
        if(i>=nums.size() || target<0) return false;

        if(dp[i][target]!=-1) return dp[i][target];

        int nottake=solve(i+1,target,nums,dp);
        int take=solve(i+1,target-nums[i],nums,dp);

        return dp[i][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i:nums){
             sum+=i;
        }
          if(sum%2!=0) return false;

        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(0,target,nums,dp);
    }
};