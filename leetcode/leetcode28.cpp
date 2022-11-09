class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length(), n=needle.length();
        vector<int> next(n);
        // get next
        next[0]=-1;
        int j=-1;
        for(int i=1;i<n;i++){
            while(j!=-1 && needle[i]!=needle[j+1])
                j=next[j];
            if(needle[i]==needle[j+1])
                j++;
            if(j==-1 || needle[j+1]!=needle[i+1])
                next[i]=j;
            else
                next[i]=next[j];
        }
        // kmp
        j=-1;
        for(int i=0;i<m;i++){
            while(j!=-1 && haystack[i]!=needle[j+1])
                j=next[j];
            if(haystack[i]==needle[j+1])
                j++;
            if(j==n-1)
                return i-n+1;
        }
        return -1;
    }
};