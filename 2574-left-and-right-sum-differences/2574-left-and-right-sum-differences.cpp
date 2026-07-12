class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        int pre=0;
        for(int i=0;i<n;i++){
            left[i]=pre;
            pre+=nums[i];
        }

        int suf=0;
        for(int i=n-1;i>=0;i--){
            right[i]=suf;
            suf+=nums[i];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};