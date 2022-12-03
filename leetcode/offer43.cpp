class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)
            return 0;
        string nstr=to_string(n);
        int l=nstr.size();
        if(l==1){
            if(nstr[0]=='0')
                return 0;
            else
                return 1;
        }
        int firstDigitCnt;
        if(nstr[0]>'1'){
            firstDigitCnt=pow(10, l-1);
        }else{
            firstDigitCnt=atoi(nstr.substr(1, l-1).c_str())+1;
        }
        int otherDigitCnt=(nstr[0]-'0')*(l-1)*pow(10, l-2);
        int recursiveCnt=countDigitOne(atoi(nstr.substr(1, l-1).c_str()));
        return firstDigitCnt+otherDigitCnt+recursiveCnt;
    }
};