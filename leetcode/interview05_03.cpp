class Solution {
public:
    int reverseBits(int num) {
        int maxlen=1;
        int curlen=0;
        int prelen=0;
        unsigned int x=(unsigned int)(num);
        while(x!=0){
            if((x&1)>0){
                curlen++;
            }else{
                prelen=(x&2)>0?curlen:0;
                curlen=0;
            }
            x>>=1;
            maxlen=max(maxlen, curlen+prelen+1);
        }
        return min(maxlen,32);
    }
};