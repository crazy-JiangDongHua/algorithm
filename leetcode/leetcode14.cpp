class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 纵向扫描
        if(strs.size()==1)return strs[0];
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};