class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve((1<<n));
        ans.push_back(0);
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            int m=ans.size(), n=1<<(i-1);
            for(int j=m-1;j>=0;j--){
                ans.push_back(ans[j] | n);
            }
        }
        return ans;
    }
};