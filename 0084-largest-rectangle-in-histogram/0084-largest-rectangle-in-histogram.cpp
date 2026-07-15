class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;


        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty() ? n:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            int l=right[i]-left[i]-1;
            int b=heights[i];
            maxarea=max(maxarea,l*b);
        }
        return maxarea;
    }
};