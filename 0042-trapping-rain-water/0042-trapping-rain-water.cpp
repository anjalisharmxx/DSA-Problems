class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,s=height.size()-1;
        int leftmax=0,rightmax=0;
       int ans=0;
        while(l<s){
            if(height[l]<height[s]){
                if(height[l]>leftmax) leftmax=height[l];
                else ans+=leftmax-height[l];
                l++;
            }
            else{
                if(height[s]>rightmax) rightmax=height[s];
                else ans+=rightmax-height[s];
                s--;
            }
        }
        return ans;
     }
};