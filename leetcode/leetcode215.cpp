// 方法1 快速选择 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size(), nums.size()-k);
    }

    int quickselect(vector<int>& nums, int lo, int hi, int pos)
    {
        // 无需设置停止条件，因为第k大数必然存在，所以必定命中第一个if
        int mi = partition(nums, lo, hi);
        if(mi == pos)
            return nums[mi];
        else if(mi > pos)
            return quickselect(nums, lo, mi, pos);
        else
            return quickselect(nums, mi+1, hi, pos);
    }

    int partition(vector<int>& nums, int lo, int hi)
    {
        hi--;
        int randid = rand()%(hi-lo+1) + lo;
        swap(nums[randid], nums[lo]);
        int pivot = nums[lo];
        while(lo < hi)
        {
            while(lo<hi && pivot<nums[hi])
                hi--;
            nums[lo] = nums[hi];
            while(lo<hi && nums[lo]<=pivot)
                lo++;
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
};

// 方法2 建立最大堆，删除k次 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 建立最大堆
        int n = nums.size();
        build(nums, n);
        for(int i=0;i<k-1;i++)
        {
            pop(nums, n);
            n--;
        }
        return pop(nums,n);
    }

    int pop(vector<int>& nums, int n)
    {
        swap(nums[n-1], nums[0]);
        down(nums, n-1, 0);
        return nums[n-1];
    }

    void build(vector<int>& nums, int n)
    {
        //从最后一个节点的父节点开始
        for(int i=(n-1-1)/2;i>=0;i--)
        {
            down(nums, n, i);
        }
    }

    void down(vector<int>& nums, int n, int i)
    {
        int j;
        while(i != (j = selectmax(nums, n, i)))
        {
            swap(nums[i], nums[j]);
            i = j;
        }
    }

    int selectmax(vector<int>& nums, int n, int i)
    {
        int l=2*i+1, r=2*i+2, max=i;
        if(l<n && nums[l]>nums[max])
            max = l;
        if(r<n && nums[r]>nums[max])
            max = r;
        return max; 
    }
};

// 方法3 最小堆 插入n次，删除n-k次 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //最小堆
        int n = 0;
        for(int i=0;i<nums.size();i++)
        {
            insert(nums, n, i);
            n++;
            if(n > k)
            {
                pop(nums, n);
                n--;
            }
        }
        return nums[0];
    }

    void insert(vector<int>& nums, int n, int i)
    {
        nums[n] = nums[i];
        while(n>0)
        {
            int p = (n-1)/2;
            if(nums[p]<=nums[n])
                break;
            swap(nums[p], nums[n]);
            n = p;
        }
    }

    int pop(vector<int>& nums, int n)
    {
        swap(nums[n-1], nums[0]);
        down(nums, n-1, 0);
        return nums[n-1];
    }
    void down(vector<int>& nums, int n, int i)
    {
        int j;
        while(i != (j = selectmin(nums, n, i)))
        {
            swap(nums[i], nums[j]);
            i = j;
        }
    }

    int selectmin(vector<int>& nums, int n, int i)
    {
        int l=2*i+1, r=2*i+2, min=i;
        if(l<n && nums[l]<nums[min])
            min = l;
        if(r<n && nums[r]<nums[min])
            min = r;
        return min; 
    }
}; 
