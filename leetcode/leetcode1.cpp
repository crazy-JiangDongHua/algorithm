// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i=0;i<nums.size();i++)
            ht[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            if(ht.find(target-nums[i])!=ht.end() && ht[target-nums[i]]>i)
                return {i, ht[target-nums[i]]};
        }
        return {-1,-1};
    }
};

// 排序双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> tmp(nums.size());
        for(int i=0;i<nums.size();i++){
            tmp[i].first=nums[i];
            tmp[i].second=i;
        }
        sort(tmp.begin(), tmp.end());
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            if(tmp[lo].first+tmp[hi].first==target)
                return {tmp[lo].second,tmp[hi].second};
            else if(tmp[lo].first+tmp[hi].first<target)
                lo++;
            else
                hi--;
        }
        return {-1,-1};
    }
};