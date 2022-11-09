class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls=s.length(), lp=p.length();
        if(ls<lp)return {};
        int hash[26]={0};
        for(int i=0;i<lp;i++){
            hash[p[i]-'a']--;
            hash[s[i]-'a']++;
        }
        int differ=0;
        for(int i=0;i<26;i++){
            if(hash[i]!=0)
                differ++;
        }
        vector<int> ans;
        if(differ==0)
            ans.push_back(0);
        for(int i=0;i<ls-lp;i++){
            if(hash[s[i]-'a']==1){
                differ--;
            }else if(hash[s[i]-'a']==0){
                differ++;
            }
            hash[s[i]-'a']--;

            if(hash[s[i+lp]-'a']==-1){
                differ--;
            }else if(hash[s[i+lp]-'a']==0){
                differ++;
            }
            hash[s[i+lp]-'a']++;

            if(differ==0)
                ans.push_back(i+1);
        }
        return ans;
    }
};