class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,cur=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                cur++;
            }else{
                if(cur!=0){
                    ans=cur;
                    cur=0;
                }
            }
        }
        if(cur!=0)
            return cur;
        return ans;
    }
};