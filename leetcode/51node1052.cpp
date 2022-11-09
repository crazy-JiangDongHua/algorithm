#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=5010;
const int INF=0x3fffffff;
long long dp[2][MAXN];
int arr[MAXN];

int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        // 初始化，要求如果子段为负数，就输出0
        for(int i=0;i<=n;i++){
            dp[0][i]=0; // 合法状态，本身就为0
        }
        // dp[i][j] 前j个物品分i段，且最后一段一定包括第j个物品，的最大i子段和
        for(int i=1,k=1;i<=m;i++,k^=1){// k表示当前行，k^1表示上一行
            dp[k][i-1]=-INF;// 避免dp[i][i]使用了dp[i][i-1]这个状态，此时不能把第i个物品合并到最后一个子段
            long long maxpre=-INF;
            for(int j=i;j<=n-m+i;j++){
                maxpre=max(maxpre, dp[k^1][j-1]);
                dp[k][j]=max(dp[k][j-1], maxpre)+arr[j];
            }
        }
        long long ans=-INF;
        for(int i=m;i<=n;i++){
            ans=max(ans, dp[m&1][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}