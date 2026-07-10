class Solution {
public:
    vector<int> nextgre(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);        
        }
          return ans;
    }

    vector<int> nextsma(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

             if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
          
          st.push(i);        
        }
          return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        vector<int> right = nextgre(heights); 
        vector<int> left = nextsma(heights);

        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int maxarea=heights[i]*width;

            ans=max(maxarea,ans);
        }

        return ans;
    }
};

