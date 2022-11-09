class Solution {
private:
    double findk(vector<int>& nums1, vector<int>& nums2, int k){
        int id1=0, id2=0;
        int m=nums1.size(), n=nums2.size();
        while(true){
            if(id1==m)return nums2[id2+k-1];
            if(id2==n)return nums1[id1+k-1];
            if(k==1)return min(nums1[id1], nums2[id2]);

            int delta=k/2-1;
            int newid1=min(id1+delta, m-1);
            int newid2=min(id2+delta, n-1);
            if(nums1[newid1]<=nums2[newid2]){
                k-=newid1-id1+1;
                id1=newid1+1;
            }else{
                k-=newid2-id2+1;
                id2=newid2+1;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if((m+n)%2==1){
            return findk(nums1, nums2, (m+n)/2+1);
        }else{
            return (findk(nums1, nums2, (m+n)/2) + findk(nums1, nums2, (m+n)/2+1))/2;
        }
    }
};