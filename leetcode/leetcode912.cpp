// 快排 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size());
        return nums;
    }

    void quicksort(vector<int>& nums, int lo, int hi)
    {
        if(hi-lo<2)
            return;
        int mi = partition(nums, lo, hi);
        quicksort(nums, lo, mi);
        quicksort(nums, mi+1, hi);
    }

    int partition(vector<int>& nums, int lo, int hi)
    {
        hi--;
        int randid = rand()%(hi-lo+1) + lo;
        swap(nums[lo], nums[randid]);
        int pivot = nums[lo];
        while(lo<hi)
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

// 归并排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size());
        return nums;
    }
    
    void mergesort(vector<int>& nums, int lo, int hi)
    {
        if(hi-lo<2)
            return;
        int mi = lo+(hi-lo)/2;
        mergesort(nums, lo, mi);
        mergesort(nums, mi, hi);

        vector<int> temp(mi-lo, 0);
        for(int i=lo;i<mi;i++)
        {
            temp[i-lo] = nums[i];
        }

        int i=lo, j=mi, k=lo;
        while(i<mi && j<hi)
        {
            if(temp[i-lo] <= nums[j])
            {
                nums[k++] = temp[i-lo];
                i++;
            }
            else
                nums[k++] = nums[j++];
        }
        while(i<mi)
        {
            nums[k++] = temp[i-lo];
            i++;
        }
        while(j<hi)
            nums[k++] = nums[j++];
    }
    
};
