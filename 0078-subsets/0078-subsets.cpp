class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& ans, vector<vector<int>>& allsubset){
        if(i==nums.size()){
            allsubset.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        solve(i+1,nums,ans,allsubset);
        ans.pop_back();
        solve(i+1,nums,ans,allsubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;

        solve(0,nums,ans,allsubset);
        return allsubset;
    }
};