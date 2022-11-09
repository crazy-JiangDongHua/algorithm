// 大牛写法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int lo=1,hi=2;
        while(hi<nums.size()){
            // 当且仅当上一个元素和当前元素相同时，当前元素不需要保留
             if(nums[lo-1]!=nums[hi]){
                 nums[++lo]=nums[hi];
             }
             hi++;
        }
        return lo+1;
    }
};

// 我的写法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int lo=0,hi=1,cnt=1;
        while(hi<nums.size()){
            if(nums[lo]!=nums[hi]){
                nums[++lo]=nums[hi];
                cnt=1;
                hi++;
            }else{
                cnt++;
                if(cnt==2){
                    nums[lo+1]=nums[lo];
                    lo++;
                }else{
                    while(hi<nums.size() && nums[lo]==nums[hi])
                        hi++;
                }
            }
        }
        return lo+1;
    }
};