class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int pre=0;
        int cur=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            cur=(pre+cur)%mod;
            pre=(cur-pre+mod)%mod;
        }
        return cur;
    }
};