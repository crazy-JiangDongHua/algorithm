class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left=newInterval[0];
        int right=newInterval[1];
        bool place=false;
        for(vector<int>& interval:intervals){
            if(interval[0]>right){
                if(!place){
                    ans.push_back({left, right});
                    place=true;
                }
                ans.emplace_back(interval);
            }else if(interval[1]<left){
                ans.emplace_back(interval);
            }else{
                left=min(left, interval[0]);
                right=max(right, interval[1]);
            }
        }
        if(!place){
            ans.push_back({left, right});
        }
        return ans;
    }
};