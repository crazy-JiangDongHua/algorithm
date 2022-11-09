class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3)return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            // 去重
            if(i>0 and nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int lo=j+1, hi=nums.size()-1;
                while(lo<hi){
                    // 去重，前三个数不重复以后，第四个数自然不重复
                    if(lo>j+1 && nums[lo]==nums[lo-1]){
                        lo++;continue;
                    }
                    long long sum=(long long)nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        lo++;hi--;
                    }else if(sum>target){
                        hi--;
                    }else{
                        lo++;
                    }
                }
            }
        }
        return ans;
    }
};