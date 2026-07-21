class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> ans;

        int i=0; int j=i+1;
        ans.push_back(nums[i]);
        while(j<n){
            if(nums[i]!=nums[j]){
                ans.push_back(nums[j]);
                i=j;
            }
            j++;
        }
       nums=ans;
        return nums.size();
    }
};