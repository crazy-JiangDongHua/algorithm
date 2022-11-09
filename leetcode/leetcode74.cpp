class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int lo=0, hi=m*n;
        while(lo < hi)
        {
            int mi = lo+(hi-lo)/2;
            int x = mi/n, y = mi%n;
            if(matrix[x][y]==target)
                return true;
            else if(matrix[x][y]>target)
                hi = mi;
            else
                lo = mi + 1;
        }
        return false;
    }
};
