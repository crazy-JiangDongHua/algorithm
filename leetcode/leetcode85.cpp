class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m=matrix.size(), n=matrix[0].size();
        int ans=0;
        vector<int> H(n,0);
        vector<int> L(n,-1);
        vector<int> R(n,n);
        for(int i=0;i<m;i++){
            int left=-1, right=n;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    H[j]++;
                    L[j]=max(L[j], left);
                }else{
                    left=j;
                    H[j]=0;L[j]=-1;R[j]=n;
                }
            }

            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    R[j]=min(R[j], right);
                    ans=max(ans, H[j]*(R[j]-L[j]-1));
                }else{
                    right=j;
                }
            }
        }
        return ans;
    }
};