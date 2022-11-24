class Solution {
private:
    void permutation(const string& s, int i, vector<string>& ans, string& s_tmp, vector<bool>& vis){
        if(i==s.size()){
            ans.emplace_back(s_tmp);
            return;
        }
        for(int j=0;j<s.size();j++){
            if(!vis[j] && !(j>0&&s[j-1]==s[j]&&!vis[j-1])){
                vis[j]=true;
                s_tmp.push_back(s[j]);
                permutation(s, i+1, ans, s_tmp, vis);
                s_tmp.pop_back();
                vis[j]=false;
            }
        }
    }
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        vector<bool> vis(s.size(), false);
        string s_tmp;
        permutation(s, 0, ans, s_tmp, vis);
        return ans;
    }
};