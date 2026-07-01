class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i:nums){
            mp[i]++;
        }
        
        vector<pair<int,int>> pairs;

        for(auto &i:mp){
            pairs.push_back({i.second,i.first});
        }

        sort(pairs.rbegin(),pairs.rend());

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pairs[i].second);
        }
        return ans;
    }
};