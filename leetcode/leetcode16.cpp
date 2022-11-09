class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
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
                int sum=nums[lo]+nums[hi]+nums[i];
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                }
                if(sum>=target){
                    hi--;
                }else{
                    lo++;
                }
            }
        }
        return ans;
    }
};