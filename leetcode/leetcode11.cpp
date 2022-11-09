class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end=height.size()-1, res=0;
        while(start < end)
        {
            res = max((end-start)*min(height[start], height[end]), res);
            if(height[start] <= height[end])
                start++;
            else
                end--;
        }
        return res;
    }
};
