class Solution {
private:
    bool isValid(const char& c){
        return ('0'<=c&&c<='9') || ('a'<=c&&c<='z') || ('A'<=c&&c<='Z');
    }

    char convert(const char& c){
        if('A'<=c&&c<='Z')
            return c-'A'+'a';
        return c;
    }
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            while(i<j && !isValid(s[i]))
                i++;
            while(i<j && !isValid(s[j]))
                j--;
            if(i>=j)
                return true;
            else if(convert(s[i]) != convert(s[j]))
                return false;    
        }
        return true;
    }
};