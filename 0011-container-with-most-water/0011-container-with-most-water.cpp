class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int maxarea=0;
        int right=height.size()-1;
        while(left<right){
            int l=min(height[right],height[left]);
            int b=right-left;

            maxarea=max(maxarea,l*b);
            if(height[left]<height[right]){
                left++;
            }
            else right--;
        }
        return maxarea;
    }
};