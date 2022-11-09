class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> frac(n, 1);
        for(int i=2;i<n;i++)
            frac[i]=frac[i-1]*i;
        string ans(n,'0');
        vector<int> flag(n+1,1);
        k--;
        for(int i=1;i<=n;i++){
            int order=k/frac[n-i]+1;
            int j=1;
            while(order>0){
                order-=flag[j++];
            }
            ans[i-1]=j-1+'0';
            flag[j-1]=0;
            k%=frac[n-i];
        }
        return ans;
    }
};