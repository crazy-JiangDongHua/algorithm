int getNumberSameAsIndex(vector<int>& num){
    int l=0,r=nums.size(),m;
    while(l<r){
        m=l+((r-l)>>1);
        if(nums[m]==m)
            return m;
        else if(nums[m]<m)
            l=m+1;
        else
            r=m-1;
    }
    // 没找到
    return -1;
}