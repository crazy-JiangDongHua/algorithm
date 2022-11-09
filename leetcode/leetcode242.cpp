class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={0};
        for(char& c:s)
            cnt[c-'a']++;
        for(char& c:t)
            cnt[c-'a']--;
        for(int& num:cnt)
            if(num!=0)
                return false;
        return true;
    }
};