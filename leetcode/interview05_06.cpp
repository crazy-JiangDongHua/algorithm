class Solution {
public:
    int convertInteger(int A, int B) {
        int cnt=0;
        for(unsigned int c=A^B;c>0;c&=(c-1))
            cnt++;
        return cnt;
    }
};