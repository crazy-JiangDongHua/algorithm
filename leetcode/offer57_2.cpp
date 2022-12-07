class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target<1)
            throw exception();
        vector<vector<int>> ans;
        int l=1, r=2, m=(target+1)/2, sum=3;
        while(l<m){
            if(sum==target){
                vector<int> res;
                for(int i=l;i<=r;i++){
                    res.push_back(i);
                }
                ans.emplace_back(res);
                sum-=l;l++;
                r++;sum+=r;
            }else if(sum<target){
                r++;
                sum+=r;
            }else{
                sum-=l;
                l++;
            }
        }
        return ans;
    }
};