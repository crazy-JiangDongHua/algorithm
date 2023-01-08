class Solution {
public:
    string compressString(string S) {
        int cnt=0;
        string ans="";
        for(int i=0;i<S.length();i++){
            cnt++;
            if(i+1>=S.length() || S[i]!=S[i+1]){
                ans+=S[i];
                ans+=to_string(cnt);
                cnt=0;
            }
        }
        return S.length()<=ans.length()?S:ans;
    }
};