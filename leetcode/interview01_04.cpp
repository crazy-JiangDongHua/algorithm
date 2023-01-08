class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool hash[128]={false};
        for(char& c:s){
            hash[c]=!hash[c];
        }
        int cnt=0;//奇数频率字符串的个数
        for(int isodd:hash){
            if(isodd)
                cnt++;
            // 最多一个是奇数频率，该单词在回文串最中间
            if(cnt>1)
                return false;
        }
        return true;
    }
};