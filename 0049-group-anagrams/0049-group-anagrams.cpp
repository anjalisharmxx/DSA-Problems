class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string c:strs){
            string k=c;
            sort(k.begin(),k.end());
            mp[k].push_back(c);
        }

        for(auto &i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};