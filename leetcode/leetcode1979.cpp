class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = 1010, max = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<min)
                min = nums[i];
            if(nums[i]>max)
                max = nums[i];
        }
        return gcd(max, min);
    }

    int gcd(int a, int b)
    {
        return b!=0?gcd(b, a%b):a;
    }
};
