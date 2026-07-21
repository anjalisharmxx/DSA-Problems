class Solution {
public:
    int trap(vector<int>& height) {
        int s=0,e=height.size()-1;
        int lmax=0,rmax=0;
        int ans=0;

        while(s<e){
             lmax=max(lmax,height[s]);
             rmax=max(rmax,height[e]);
             
             if(lmax<rmax){
                ans+= lmax-height[s];
                s++;
             }
             else{
                ans+=rmax-height[e];
                e--;
             }
        }
        return ans;
    }
};