class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s=countAndSay(n-1);
        string ans;
        int i,j;
        for(i=0,j=1;j<s.length();j++){
            if(s[i]!=s[j]){
                ans=ans+to_string(j-i)+s.substr(i,1);
                i=j;
            }
        }
        ans=ans+to_string(j-i)+s.substr(i,1);
        return ans;
    }
};