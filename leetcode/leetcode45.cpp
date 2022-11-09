class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0, right=0, step=0, tar=nums.size()-1;
        if(nums.size()==1)
            return 0;
        while(left<=right)
        {
            step++;
            int old_right = right;
            for(int i=left;i<=old_right;i++)
            {
                right = max(right, i+nums[i]);
                if(right >= tar)
                    return step;
            }
            left = old_right;
        }
        return -1;//不能到达最后一个点，但是这是不可能的
    }
};
