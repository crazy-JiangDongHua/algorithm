class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans(a.size(), 1);
        int n=ans.size();
        for(int i=1;i<n;i++){
            ans[i]*=ans[i-1]*a[i-1];
        }
        int tmp=1;
        for(int i=n-2;i>=0;i--){
            tmp*=a[i+1];
            ans[i]*=tmp;
        }
        return ans;
    }
};