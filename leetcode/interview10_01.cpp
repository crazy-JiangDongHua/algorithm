class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]<=B[j])
                A[k--] = B[j--];
            else
                A[k--] = A[i--];
        }
        while(j>=0)
            A[k--] = B[j--];
    }
};
