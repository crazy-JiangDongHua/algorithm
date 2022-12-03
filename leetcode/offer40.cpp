// 方法一，基于找第k大和-
class InputException : public exception{
private:
    int flag;
public:
    InputException(int f){
        flag=f;
    }
    const char* what() const throw(){
        if(flag==1)
            return "The size of input array is smaller than k";
        else if(flag==2)
            return "k<0";
        else
            return "undefine error";
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
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<0)
            throw InputException(2);
        if(k==0)
            return {};
        if(arr.size()<k)
            throw InputException(1);
        int l=0,r=arr.size()-1;
        int id;
        while((id=partition(arr, l, r))!=k-1){
            if(id>k-1){
                r=id-1;
            }else{
                l=id+1;
            }
        }
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};

// 最大堆
class InputException : public exception{
private:
    int flag;
public:
    InputException(int f){
        flag=f;
    }
    const char* what() const throw(){
        if(flag==1)
            return "The size of input array is smaller than k";
        else if(flag==2)
            return "k<0";
        else
            return "undefine error";
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
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<0)
            throw InputException(2);
        if(k==0)
            return {};
        if(arr.size()<k)
            throw InputException(1);
        priority_queue<int> pq;
        for(int& num:arr){
            if(pq.size()<k){
                pq.push(num);
            }else if(pq.top()>num){
                pq.pop();
                pq.push(num);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};