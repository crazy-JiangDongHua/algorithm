// 方法一 基于partition，找第k大
class ArrEmptyException : public exception{
public:
    const char* what() const throw(){
        return "The input array is empty.";
    }
};

class NoAnswerException : public exception{
public:
    const char* what() const throw(){
        return "The input case has no answer.";
    }
};

class Solution {
private:
    int partition(vector<int>& nums, int l, int r){
        int pivot=nums[l];
        while(l<r){
            while(l<r && nums[r]>pivot)
                r--;
            nums[l]=nums[r];
            while(l<r && nums[l]<=pivot)
                l++;
            nums[r]=nums[l];
        }
        nums[l]=pivot;
        return l;
    }

    bool check(vector<int>& nums, int ans){
        int cnt=0;
        for(int& num:nums){
            if(num==ans)
                cnt++;
        }
        return cnt>nums.size()/2;
    }
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
            throw ArrEmptyException();
        int l=0, r=nums.size()-1, m=nums.size()/2;
        int id;
        while((id=partition(nums, l, r))!=m){
            if(id<m){
                l=id+1;
            }else{
                r=id-1;
            }
        }

        // 检查答案是否存在
        if(!check(nums, nums[m]))
            throw NoAnswerException();
        
        return nums[m];
    }
};


// 方法二 Boyer-Moore 投票算法
class ArrEmptyException : public exception{
public:
    const char* what() const throw(){
        return "The input array is empty.";
    }
};

class NoAnswerException : public exception{
public:
    const char* what() const throw(){
        return "The input case has no answer.";
    }
};

class Solution {
private:
    bool check(vector<int>& nums, int ans){
        int cnt=0;
        for(int& num:nums){
            if(num==ans)
                cnt++;
        }
        return cnt>nums.size()/2;
    }
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
            throw ArrEmptyException();
        
        int candidate=0, cnt=0;
        for(int& num:nums){
            if(cnt==0){
                candidate=num;
                cnt=1;
            }else{
                if(candidate==num)
                    cnt++;
                else
                    cnt--;
            }
        }

        // 检查答案是否存在
        if(!check(nums, candidate))
            throw NoAnswerException();
        
        return candidate;
    }
};