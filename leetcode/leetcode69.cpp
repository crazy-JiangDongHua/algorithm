class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int hi=x;//解空间为[0,n]，是左闭右闭形式
        while(lo<=hi)
        {
            int mi= lo + (hi-lo)/2;
            if((long long)mi*mi<=x)
                lo=mi+1;
            else
                hi=mi-1;
        }
        return hi;
    }
};
