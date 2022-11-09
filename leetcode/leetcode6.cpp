class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.length()<=numRows)return s;
        vector<string> mat(numRows);
        for(int i=0,x=0,p=2*numRows-2;i<s.length();i++){
            mat[x]+=s[i];
            i%p<numRows-1?x++:x--;
        }
        string ans;
        for(string& row:mat)
            ans+=row;
        return ans;
    }
};