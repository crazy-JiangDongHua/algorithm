class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix.size()!=matrix[0].size())
            return;
        int n=matrix.size(), temp, offset;
        for(int layer=0;layer<n/2;layer++){
            int first=layer, last=n-1-layer;
            for(int i=first;i<last;i++){
                offset=n-i-1;
                // 存储右边
                temp=matrix[i][last];
                // 上边复制到右边
                matrix[i][last]=matrix[layer][i];
                // 左边复制到上面
                matrix[layer][i]=matrix[offset][first];
                // 下面复制到左边
                matrix[offset][first]=matrix[last][offset];
                // 右边复制到下面
                matrix[last][offset]=temp;
                // 
            }
        }
    }
};