class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
       int maxii = nums[0];

        int pre=1;
        for(int i=0;i<n;i++){
            pre*=nums[i];
            maxii = max(maxii, pre);

            if (pre == 0) {
                pre = 1;
            }
        }

        int suf = 1;
        for(int i = n - 1; i >= 0; i--) {
            suf *= nums[i];
            maxii = max(maxii, suf);

            if (suf == 0) {
                suf = 1;
            }
        }
        return maxii;
    }
};