class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0, n=heights.size();
        stack<int> stk;
        vector<int> left(n, 0);
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && heights[stk.top()]>=heights[i])
            {
                int j = stk.top();
                stk.pop();
                res = max(res, heights[j]*(i-left[j]-1));
            }
            if(stk.empty())
            {
                left[i] = -1;
            }
            else // heigths[stk.top()]<heights[i]
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            int j = stk.top();
            stk.pop();
            res = max(res, heights[j]*(n-left[j]-1));
        }
        return res;
    }
};
