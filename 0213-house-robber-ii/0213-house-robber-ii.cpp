class Solution {
public:
    int fun(int index,vector<int>& nums, vector<int>& dp){
        if(index<0) return 0;
        if(index==0) return nums[0];
        
        if(dp[index]!=-1) return dp[index];

        int nottake=0+fun(index-1,nums,dp);
        int take=nums[index]+fun(index-2,nums,dp);

        return dp[index]=max(nottake,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> first;
        vector<int> sec;

        for(int i=0;i<n-1;i++){
            first.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            sec.push_back(nums[i]);
        }
        
        vector<int> dp1(first.size(), -1);
        vector<int> dp2(sec.size(), -1);

        int ans1=fun(first.size()-1,first,dp1);
        int ans2=fun(sec.size()-1,sec,dp2);

        return max(ans1,ans2);
    }
};