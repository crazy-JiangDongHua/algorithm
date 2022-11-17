class DivideZero: public exception{
    const char* what() const throw(){
        return "divide zero";
    }
};
class Solution {
private:
    double noExceptionPow(double x, long long n){
        double ans=1.0;
        double base=x;
        while(n){
            if(n&1)
                ans*=base;
            base*=base;
            n=n>>1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if(fabs(x)<1e-6 && n<0)
            throw DivideZero();
        long long absn=n<0?-(long long)(n):n;
        double ans=noExceptionPow(x, absn);
        if(fabs(ans)<1e-6 && n<0)
            throw DivideZero();
        return n<0?1/ans:ans;
    }
};