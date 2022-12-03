// 方法一 归并排序
class Solution {
private:
    int merge(vector<int>& nums, vector<int>& tmp, int l, int m, int r){
        for(int i=l;i<m;i++)
            tmp[i]=nums[i];
        int i=l,j=m,k=l,cnt=0;
        while(i<m){
            if(j>=r || tmp[i]<=nums[j]){
                nums[k]=tmp[i];
                i++;
                cnt+=j-m;
            }else{
                nums[k]=nums[j];
                j++;
            }
            k++;
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(r-l<=1)
            return 0;
        int m=l+((r-l)>>1);
        int lnum=reversePairs(nums, tmp, l, m);
        int rnum=reversePairs(nums, tmp, m, r);
        int mnum=merge(nums, tmp, l, m, r);
        return lnum+rnum+mnum;
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> copy=nums;
        vector<int> tmp(nums.size(),0);
        return reversePairs(copy, tmp, 0, nums.size());
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