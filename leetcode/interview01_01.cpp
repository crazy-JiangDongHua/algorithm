// 方法一 哈希表
class BadInputException: public exception{
    const char* what() const throw(){
        return "Bad Input";
    }
};
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.length()>26)
            return false;
        int hash[26]={0};
        int index;
        for(const char& c:astr){
            if(c<'a' || c>'z')
                throw BadInputException();
            index=c-'a';
            if(hash[index]!=0)
                return false;
            hash[index]=1;
        }
        return true;
    }
};

// 方法二 位向量哈希表
class BadInputException: public exception{
    const char* what() const throw(){
        return "Bad Input";
    }
};
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.length()>26)
            return false;
        int hash=0;
        int index;
        for(const char& c:astr){
            if(c<'a' || c>'z')
                throw BadInputException();
            index=c-'a';
            if((hash&(1<<index))>0)
                return false;
            hash|=1<<index;
        }
        return true;
    }
};