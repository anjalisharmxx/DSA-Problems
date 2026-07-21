class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlength=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxlength) return false;
            maxlength=max(maxlength,i+nums[i]);
        }
        return true;
    }
};