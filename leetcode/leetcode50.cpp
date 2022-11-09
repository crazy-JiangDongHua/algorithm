class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int absn = abs(n);
        while(absn>0)
        {
            if(absn&1)
                res *= x;
            x = x*x;
            absn = absn>>1;
        }
        if(n<0)
            return 1/res;
        return res;
    }
};
