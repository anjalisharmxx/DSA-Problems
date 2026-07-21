class Solution {
public:
    vector<string> ans;
    void solve(int n,int open , int close,string curr){
        if(open==n && close==n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
                solve(n,open+1,close,curr+'(');
        }

        if(close<open){
            solve(n,open,close+1,curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n<1){
            return {};
        }
        solve(n,0,0,"");
        return ans;
    }
};