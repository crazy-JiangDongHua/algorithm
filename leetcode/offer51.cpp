// 方法一 归并排序
class Solution {
private:
int merge(vector<int>& nums, int l, int m, int r){
    vector<int> tmp(nums.begin()+l, nums.begin()+m);
    int sum=0,i=0,j=m,k=l;
    while(k<r){
        if(j>=r || (i<tmp.size() && tmp[i]<=nums[j]))
            nums[k++]=tmp[i++];
        else{
            nums[k++]=nums[j++];
            sum+=tmp.size()-i;
        }
    }
    return sum;
}
int divcmp(vector<int>& nums, int l, int r){
    if(r-l<=1)return 0;
    int m=(l+r)/2;
    return divcmp(nums,l,m)+divcmp(nums,m,r)+merge(nums,l,m,r);
}
public:
    int reversePairs(vector<int>& nums) {
        return divcmp(nums, 0, nums.size());
    }
};

// 树状数组
class Solution {
private:
    class TreeArray{
        private:
            vector<int> c;
            int lowbit(int x){
                return x&(-x);
            }
        public:
            TreeArray(int n){
                c.assign(n+1, 0);
            }
            void update(int x, int v){
                for(int i=x;i<c.size();i+=lowbit(i))
                    c[i]+=v;
            }
            int getSum(int x){
                int sum=0;
                for(int i=x;i>0;i-=lowbit(i))
                    sum+=c[i];
                return sum;
            }
    };
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp=nums;
        sort(tmp.begin(), tmp.end());
        TreeArray ta(nums.size()+1);
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            // 离散化
            int idx=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin()+1;
            ta.update(idx,1);
            ans+=ta.getSum(idx-1);
        }
        return ans;
    }
};