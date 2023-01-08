class Solution {
public:
    string replaceSpaces(string S, int length) {
        int newlength=length;
        for(int i=0;i<length;i++)
            if(S[i]==' ')
                newlength+=2;
        for(int i=length-1, j=newlength-1;i>=0;i--){
            if(S[i]==' '){
                S[j--]='0';
                S[j--]='2';
                S[j--]='%';
            }else{
                S[j--]=S[i];
            }
        }
        return S.substr(0, newlength);
    }
};