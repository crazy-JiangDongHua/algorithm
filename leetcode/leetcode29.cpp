class Solution {
private:
    // 自己实现快速乘 判断z*y>=x
    // 之所以不直接求乘积，是因为怕越界
    bool check(int x, int y, int z){
        int p=y, sum=0;
        while(z>0){
            if((z&1)==1){
                // 要保证sum+p>=x
                // 不写sum+p>=x是因为防止sum+p越界
                // 因为x肯定不越界，x减去一个负数，也肯定不会越界
                if(sum<x-p){
                    return false;
                }
                sum+=p;
            }
            z=z>>1;
            // 如果z不等于0，那么还需要继续加pp
            // 同理 保证p+p>=x
            if(z!=0){
                if(p<x-p)
                    return false;
                else
                    p+=p;
            }
        }
        return true;
    }
public:
    int divide(int dividend, int divisor) {
        // 特殊情况
        if(dividend==INT_MIN){
            if(divisor==-1)return INT_MAX;
            else if(divisor==1)return INT_MIN;
        }
        // if(divisor==INT_MIN){
        //     if(dividend==INT_MIN)return 1;
        //     else return 0;
        // }
        // if(dividend==0)
        //     return 0;
        
        // INT_MIN*-1越界，所以被除数和除数都转为负数
        bool p=false;
        if(dividend>0){
            dividend=-dividend;
            p=!p;
        }
        if(divisor>0){
            divisor=-divisor;
            p=!p;
        }
        // 寻找最大的res 使得res*divisor>=dividend>=(res+1)*divisor
        // 排除特殊情况，res取值范围为[0,INT_MAX]
        int l=0,r=INT_MAX;
        while(l<=r){
            int m=l+((r-l)>>1);
            if(check(dividend, divisor, m)){
                // 防止再加1越界
                if(m==INT_MAX){
                    break;
                }
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return p?-r:r;
    }
};