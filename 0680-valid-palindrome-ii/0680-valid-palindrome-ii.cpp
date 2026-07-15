class Solution {
public:
    bool solve(string &s, int st,int e){
        int n=s.size();
        while(st<e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;e--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st=0,e=s.size()-1;
        while(st<e){
            if(s[st]==s[e]){
                st++,e--;
            }
            else{
               return solve(s,st+1,e) || solve(s,st,e-1);
            }
        }
        return true;
    }
};