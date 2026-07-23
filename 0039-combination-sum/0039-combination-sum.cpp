class Solution {
public:
    void solve(int i,vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& allans){
        if(i<0 || target<0) return ;

        if(target==0){
           allans.push_back(ans);
           return ;
        }

        if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],ans,allans);
            ans.pop_back();
        }
        solve(i-1,candidates,target,ans,allans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ans;
        vector<vector<int>> allans;
        solve(n-1,candidates,target,ans,allans);
        return allans;
    }
};
