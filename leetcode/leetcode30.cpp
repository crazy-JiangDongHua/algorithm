class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){
        int num=words.size(), n=words[0].size();
        int ls=s.size(), lw=num*n;
        vector<int> ans;
        if(ls<lw)return ans;
        for(int i=0;i<n&&i+lw<=ls;i++){
            unordered_map<string, int> ht;
            for(int j=0;j<num;j++){
                ht[words[j]]--;
                ht[s.substr(i+j*n,n)]++;
            }
            int differ=0;
            for(auto& item:ht){
                if(item.second!=0)
                    differ++;
            }
            if(differ==0)ans.push_back(i);
            for(int start=i;start<=ls-lw-n;start+=n){
                if(ht[s.substr(start,n)]==1){
                    differ--;
                }else if(ht[s.substr(start,n)]==0){
                    differ++;
                }
                ht[s.substr(start,n)]--;

                if(ht[s.substr(start+lw,n)]==-1){
                    differ--;
                }else if(ht[s.substr(start+lw,n)]==0){
                    differ++;
                }
                ht[s.substr(start+lw,n)]++;

                if(differ==0)
                    ans.push_back(start+n);
            }
        }
        return ans;
    }
};