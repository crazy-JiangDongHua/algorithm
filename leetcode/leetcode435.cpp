class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res=0, right=intervals[0][1], i=1;
        for(;i<intervals.size();i++)
        {
            if(intervals[i][0]<right)
                res++;
            else
                right=intervals[i][1];
        }
        return res;
    }

    static bool cmp(const vector<int>& u, const vector<int>& v)
    {
        return u[1]<v[1];
    }
};
