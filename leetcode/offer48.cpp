class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> posarr(256,-1);
        int curlen=0, maxlen=0;
        for(int i=0,n=s.length();i<n;i++){
            int pos=posarr[s[i]];
            if(pos<0 || i-pos>curlen){
                curlen++;
            }else{
                maxlen=max(maxlen, curlen);
                curlen=i-pos;
            }
            posarr[s[i]]=i;
        }
        maxlen=max(maxlen, curlen);
        return maxlen;
    }
};