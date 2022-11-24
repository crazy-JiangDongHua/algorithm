class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        if(matrix[0].size()==0)
            return ans;
        int rl=0, rh=matrix.size(), cl=0, ch=matrix[0].size();
        while(true){
            for(int i=cl;i<ch;i++)
                ans.push_back(matrix[rl][i]);
            rl++;
            if(rl>=rh)break;
            for(int i=rl;i<rh;i++)
                ans.push_back(matrix[i][ch-1]);
            ch--;
            if(cl>=ch)break;
            for(int i=ch-1;i>=cl;i--)
                ans.push_back(matrix[rh-1][i]);
            rh--;
            if(rl>=rh)break;
            for(int i=rh-1;i>=rl;i--)
                ans.push_back(matrix[i][cl]);
            cl++;
            if(cl>=ch)break;
        }
        return ans;
    }
};