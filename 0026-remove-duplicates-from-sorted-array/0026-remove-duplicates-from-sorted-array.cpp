class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0) return 0;

        int i=0;
        int j=i+1;
        ans.push_back(nums[i]);
        while(j<nums.size()){
             if(nums[i]!=nums[j]){
                ans.push_back(nums[j]);
                i=j;
            }
            j++;
        }
        nums=ans;
        return ans.size();
    }
};