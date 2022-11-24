class Solution {
private:
    bool verifyPostorder(vector<int>& postorder, int l, int r){
        if(l>=r)
            return true;
        int root=postorder[r-1];
        int m;
        for(m=l;m<r-1;m++)
            if(postorder[m]>root)
                break;
        for(int i=m;i<r-1;i++)
            if(postorder[i]<root)
                return false;
        return verifyPostorder(postorder, l, m)&&verifyPostorder(postorder, m, r-1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size());
    }
};