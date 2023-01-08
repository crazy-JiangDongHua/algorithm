// 方法一 哈希表
class BadInputException: public exception{
    const char* what() const throw(){
        return "Bad Input";
    }
};
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        int hash[26]={0};
        int index;
        for(char& c:s1){
            if(c<'a' || c>'z')
                throw BadInputException();
            index=c-'a';
            hash[index]++;
        }
        for(char& c:s2){
            if(c<'a' || c>'z')
                throw BadInputException();
            index=c-'a';
            hash[index]--;
        }
        for(int& cnt:hash){
            if(cnt!=0)
                return false;
        }
        return true;
    }
};