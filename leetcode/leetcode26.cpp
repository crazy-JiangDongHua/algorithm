class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pred=0, last=1;
        while(last<nums.size())
        {
            while(last<nums.size() && nums[pred]==nums[last])
                last++;
            if(last<nums.size())
            {
                nums[++pred] = nums[last++];
            }
        }
        return pred+1;
    }
};
