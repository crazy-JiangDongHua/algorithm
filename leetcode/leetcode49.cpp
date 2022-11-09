class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for(string& s:strs){
            string key=s;
            sort(key.begin(), key.end());
            mp[key].emplace_back(s);
        }
        for(auto& item:mp){
            ans.emplace_back(item.second);
        }
        return ans;
    }
};