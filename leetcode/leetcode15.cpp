class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            // 因为要不重复
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            // 确定a以后，那么b+c的target就是-a，可以用双指针
            int target = -nums[i];
            // 保证不重复，第二轮遍历的元素一定在第一轮之后
            int k = n-1;
            for(int j=i+1;j<n;j++) 
            {
                // 不能重复，这里i不重复，其实也保证了j不重复
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                while(j<k && nums[j]+nums[k]>target)
                    k--;
                if(j==k)
                    break;
                if(nums[j]+nums[k]==target)
                    res.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return res;
    }
};

// 第二次写的
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            // 去重，不枚举之前已经枚举过的
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int lo=i+1, hi=nums.size()-1;
            while(lo<hi){
                // 去重，前两个数不重复以后，第三个数自然不重复
                if(lo>i+1 && nums[lo]==nums[lo-1]){
                    lo++;continue;
                }
                if(nums[lo]+nums[hi]==-nums[i]){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;hi--;
                }else if(nums[lo]+nums[hi]>-nums[i]){
                    hi--;
                }else{
                    lo++;
                }
            }
        }
        return ans;
    }
};
