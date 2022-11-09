// 我写的
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0,r=matrix[0].size(),u=0,d=matrix.size();
        while(l<r && u<d){
            for(int i=l;i<r;i++)
                ans.push_back(matrix[u][i]);
            for(int i=u+1;i<d;i++)
                ans.push_back(matrix[i][r-1]);
            if(d-u>1)
            for(int i=r-2;i>=l;i--)
                ans.push_back(matrix[d-1][i]);
            if(r-l>1)
            for(int i=d-2;i>u;i--)
                ans.push_back(matrix[i][l]);
            l++;r--;u++;d--;
        }
        return ans;
    }
};

// 大神写的 非常优雅，像诗一样
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0,r=matrix[0].size(),u=0,d=matrix.size();
        while(true){
            for(int i=l;i<r;i++)
                ans.push_back(matrix[u][i]);
            if(++u>=d)break;
            for(int i=u;i<d;i++)
                ans.push_back(matrix[i][r-1]);
            if(l>=--r)break;
            for(int i=r-1;i>=l;i--)
                ans.push_back(matrix[d-1][i]);
            if(u>=--d)break;
            for(int i=d-1;i>=u;i--)
                ans.push_back(matrix[i][l]);
            if(++l>=r)break;
        }
        return ans;
    }
};