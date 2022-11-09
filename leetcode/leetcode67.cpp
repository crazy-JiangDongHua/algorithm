class Solution {
public:
    string addBinary(string a, string b) {
        int la=a.length(),lb=b.length();
        int lc=max(la,lb);
        string c(lc,0);
        int carry=0,i;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(i=0;i<min(la,lb);i++){
            int temp=(a[i]-'0')+(b[i]-'0')+carry;
            c[i]=(temp%2)+'0';
            carry=temp/2;
        }
        while(i<la){
            int temp=(a[i]-'0')+carry;
            c[i]=(temp%2)+'0';
            carry=temp/2;
            i++;
        }
        while(i<lb){
            int temp=(b[i]-'0')+carry;
            c[i]=(temp%2)+'0';
            carry=temp/2;
            i++;
        }
        if(carry>0)
            c=c+"1";
        reverse(c.begin(),c.end());
        return c;
    }
};