class Solution {
private:
    bool scanInteger(string::iterator& it){
        if(*it=='+' || *it=='-')
            it++;
        return scanUnSignedInteger(it);
    }
    bool scanUnSignedInteger(string::iterator& it){
        bool flag=false;
        while('0'<=*it && *it<='9'){
            flag=true;
            it++;
        }
        return flag;
    }
    void scanSpace(string::iterator& it){
        while(*it==' ')
            it++;
    }
public:
    bool isNumber(string s){
        string::iterator it=s.begin();
        // 跳过前缀空格
        scanSpace(it);
        bool flag=scanInteger(it); 
        if(*it=='.'){
            it++;
            // 可能小数点前面没数字，也可能后面没数字，所以用或运算
            flag=scanUnSignedInteger(it)||flag;
        }
        if(*it=='e' || *it=='E'){
            it++;
            flag=scanInteger(it)&&flag;
        }
        // 跳过后缀空格
        scanSpace(it);
        if(it!=s.end())
            flag=false;
        return flag;
    }
};