class Solution {
private:
    static bool cmp(const string& m, const string& n){
        return m+n<n+m;
    };
public:
    string minNumber(vector<int>& nums) {
        vector<string> str_arr;
        for(const int& num:nums){
            str_arr.push_back(to_string(num));
        }
        sort(str_arr.begin(), str_arr.end(), cmp);
        string ans;
        for(const string& str:str_arr)
            ans+=str;
        return ans;
    }
};