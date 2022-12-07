class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zerocnt=0, gapcnt=0;
        for(int i=0, n=nums.size();i<n;i++){
            if(nums[i]==0)
                zerocnt++;
            else if(i>0 && nums[i-1]!=0){
                if(nums[i-1]==nums[i])
                    return false;
                else
                    gapcnt+=nums[i]-nums[i-1]-1;
            }
        }
        return zerocnt>=gapcnt;
    }
};