class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int size=sizeof(int)*8;
        vector<int> ans(length, 0);
        int start_offset=x1%size;
        int first_full_int=x1/size;
        if(start_offset>0)
            first_full_int++;
        int end_offset=x2%size;
        int last_full_int=x2/size;
        if(end_offset!=size-1)
            last_full_int--;
        for(int i=first_full_int;i<=last_full_int;i++)
            ans[y*(w/size)+i]=(~0);
        
        unsigned int start_mask=((unsigned int)(~0))>>(start_offset);
        unsigned int end_mask=~((((unsigned int)(~0))>>end_offset)>>1);
        if(x1/size == x2/size){ // 在同一子节
            ans[y*(w/size)+x1/size]|=(start_mask&end_mask);
        }else{
            ans[y*(w/size)+x1/size]|=start_mask;
            ans[y*(w/size)+x2/size]|=end_mask;
        }
        return ans;
    }
};