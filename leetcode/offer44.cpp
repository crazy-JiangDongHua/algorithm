class Solution {
private:
    long long numOfDight(int digit){
        if(digit==1)
            return 10;
        return 9*pow(10, digit-1);
    }
    int beginOfDigit(int digit){
        if(digit==1)
            return 0;
        return pow(10, digit-1);
    }
    int findNthDight(int n, int digit){
        int begin=beginOfDigit(digit);
        int index=n/digit+begin;
        int mod=digit-n%digit;
        for(int i=1;i<mod;i++)
            index/=10;
        return index%10;
    }
public:
    int findNthDigit(int n) {
        // bad input
        if(n<0)
            return -1;
        int digit=1;
        while(true){
            long long num=numOfDight(digit);
            if(n<digit*num)
                return findNthDight(n, digit);
            n-=digit*num;
            digit++;
        }
        return -1;
    }
};