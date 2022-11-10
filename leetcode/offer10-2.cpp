class Solution {
public:
    int numWays(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        int pre=1;
        int cur=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            cur=(pre+cur)%mod;
            pre=(cur-pre+mod)%mod;
        }
        return cur;
    }
};