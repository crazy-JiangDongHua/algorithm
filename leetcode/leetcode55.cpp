class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0, tar = nums.size()-1, i=0;
        while(i<=cur && cur<tar)
        {
            cur = max(cur, i+nums[i]);
            i++;
        }
        return cur>=tar;
    }
};
