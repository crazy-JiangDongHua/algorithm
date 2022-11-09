class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans={1};
        for(int i=2;i<=rowIndex+1;i++){
            ans.push_back(1);
            for(int j=i-2;j>=1;j--){
                ans[j]+=ans[j-1];
            }
        }
        return ans;
    }
};