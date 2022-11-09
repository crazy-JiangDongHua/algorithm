// 两个变量
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col1=false, row1=false;
        int m=matrix.size(), n=matrix[0].size();
        // 第一行
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                row1=true;break;
            }
        }
        // 第一列
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col1=true;break;
            }
        }
        // 统计
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        // 赋零
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(row1){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(col1){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};

// 一个变量
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col1=false;
        int m=matrix.size(), n=matrix[0].size();
        // 第一列
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col1=true;break;
            }
        }
        // 统计
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        // 赋零
        for(int i=m-1;i>=0;i--){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(col1){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};