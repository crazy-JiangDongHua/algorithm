class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty())return s;
        int oldlen=s.size();
        int newlen=oldlen;
        for(const char& c:s){
            if(c==' ')
                newlen+=2;
        }
        s.resize(newlen);
        int i=oldlen-1;
        int j=newlen-1;
        while(0<=i && i<j){
            if(s[i]==' '){
                s[j--]='0';
                s[j--]='2';
                s[j--]='%';
            }else{
                s[j--]=s[i];
            }
            i--;
        }
        return s;
    }
};