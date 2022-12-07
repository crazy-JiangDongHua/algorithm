class Solution {
private:
    void reverseString(string::iterator begin, string::iterator end){
        while(begin<end){
            swap(*begin, *end);
            begin++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        reverseString(s.begin(), s.end()-1);
        int charcnt=0;
        for(int i=0, n=s.length();i<n;i++){
            if(s[i]!=' '){
                if(charcnt!=0){
                    s[charcnt++]=' ';
                }
                int j=i;
                while(j<n && s[j]!=' '){
                    s[charcnt++]=s[j++];
                }
                reverseString(s.begin()+charcnt-(j-i), s.begin()+charcnt-1);
                i=j;
            }
        }
        s.erase(s.begin()+charcnt, s.end());
        return s;
    }
};