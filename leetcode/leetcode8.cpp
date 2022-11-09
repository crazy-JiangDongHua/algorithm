class Solution {
private:
public:
    int myAtoi(string s) {
        int i=0, ans=0, n=s.length();
        int sign=1;
        while(i<n && s[i]==' ')
            i++;
        if(s[i]=='+')i++;
        else if(s[i]=='-'){
            sign=-1;i++;
        }
        while(i<n && '0'<=s[i] && s[i]<='9'){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (s[i]-'0')>INT_MAX%10))
                return sign==1?INT_MAX:INT_MIN;
            ans=ans*10+(s[i]-'0');
            i++;
        }
        return ans*sign;
    }
};