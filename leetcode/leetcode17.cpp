class Solution {
private:
    void dfs(int i, string& digits, string& res, vector<string>& ans, unordered_map<char, string>& ht){
        if(i==digits.size()){
            ans.emplace_back(res);
            return;
        }
        for(char& c:ht[digits[i]]){
            res[i]=c;
            dfs(i+1, digits, res, ans, ht);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        unordered_map<char, string> ht={
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        string res(digits.size(), '0');
        dfs(0, digits, res, ans, ht);
        return ans;
    }
};