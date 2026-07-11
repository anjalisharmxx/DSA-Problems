class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int mp[256];
        int maxlen=0;
        int l=0,r=0;

        for(int i=0;i<256;i++){
            mp[i]=-1;
        }
        while(r<n){
            if(mp[s[r]]!=-1 && mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
            maxlen=max(maxlen,r-l+1);
            mp[s[r]]=r;
             r++;
        }
        return maxlen;
    }
};