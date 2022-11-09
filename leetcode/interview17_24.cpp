class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=INT_MIN;
        vector<int> ret(4,-1);
        for(int i=0;i<m;i++){
            vector<int> arr(n,0);
            for(int j=i;j<m;j++){
                int dp=0,left=-1;
                for(int k=0;k<n;k++){
                    arr[k]+=matrix[j][k];
                    dp=dp>0?arr[k]+dp:((left=k),arr[k]);
                    if(dp>ans){
                        ret[0]=i;
                        ret[1]=left;
                        ret[2]=j;
                        ret[3]=k;
                        ans=dp;
                    }
                }    
            }
        }
        return ret;
    }
};