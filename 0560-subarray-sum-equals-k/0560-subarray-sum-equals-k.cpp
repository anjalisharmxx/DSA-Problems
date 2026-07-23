class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ps(n,0);
        ps[0]=nums[0];
        unordered_map<int,int> mp;
        int count=0;

        for(int i=1;i<n;i++){
            ps[i]=nums[i]+ps[i-1];
        }

        for(int i=0;i<n;i++){
            if(ps[i]==k) count++;

            int val=ps[i]-k;
            if(mp.find(val)!=mp.end()){
                count+=mp[val];
            }
            mp[ps[i]]++;
        }
        return count;
    }
};