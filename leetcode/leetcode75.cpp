class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p0=0,p1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                swap(nums[i], nums[p1++]);
            }
            else if(nums[i]<1)
            {
                swap(nums[p0], nums[i]);
                if(p0<p1)
                {
                    swap(nums[p1], nums[i]);
                }
                p0++;p1++;
            }
        }
    }
};
