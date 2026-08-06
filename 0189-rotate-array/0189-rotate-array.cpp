class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> first;
        vector<int> sec;
        k = k % n;
        for(int i=0;i<n-k;i++){
            first.push_back(nums[i]);
        }

        for(int i=n-k;i<n;i++){
            sec.push_back(nums[i]);
        }
        
        nums.clear();
        for(int i=0;i<sec.size();i++){
            nums.push_back(sec[i]);
        }
        for(int i=0;i<first.size();i++){
            nums.push_back(first[i]);
        }
    }
};