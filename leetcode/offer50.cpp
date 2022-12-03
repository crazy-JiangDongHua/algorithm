class Solution {
public:
    char firstUniqChar(string s) {
        int ht[26]={0};
        for(const char& c:s){
            ht[c-'a']++;
        }
        for(const char& c:s){
            if(ht[c-'a']==1)
                return c;
        }
        return ' ';
    }
};