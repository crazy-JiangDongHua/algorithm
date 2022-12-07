class Solution {
private:
    int findFirstBit(const vector<int>& nums){
        int tmp=0;
        for(const int& num:nums){
            tmp^=num;
        }
        int index=0;
        while((tmp&1)==0){
            tmp>>=1;
            index++;
        }
        return index;
    }

    bool check(int num, int index){
        while(index-->0){
            num>>=1;
        }
        return num&1;
    }
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.size()<2)
            return {};
        int index=findFirstBit(nums);
        int ans1=0, ans2=0;
        for(const int& num:nums){
            if(check(num, index)){
                ans1^=num;
            }else{
                ans2^=num;
            }
        }
        return {ans1, ans2};
    }
};