class Solution {
public:
   int sol(int i,vector<int>& nums,vector<int>& dp){
    if(i<0) return 0;
    if(i==0) return nums[0];
    if(dp[i]!=-1) return dp[i];
    int nottake=0+sol(i-1,nums,dp);
    int take=nums[i]+sol(i-2,nums,dp);

    return dp[i]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();

        if (n == 1) return nums[0];

        vector<int> fir;
        vector<int> sec;

        for(int i=0;i<n-1;i++){
            fir.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            sec.push_back(nums[i]);
        }

        vector<int> dp1(fir.size(),-1);
        vector<int> dp2(sec.size(),-1);

        int ans1=sol(fir.size()-1,fir,dp1);
        int ans2=sol(sec.size()-1,sec,dp2);

        return max(ans1,ans2);
    }
};