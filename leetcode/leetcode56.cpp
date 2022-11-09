class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int left=intervals[i][0];
            int right=intervals[i][1];
            if(ans.empty() || left>ans[ans.size()-1][1]){
                ans.push_back({left,right});
            }else{
                ans[ans.size()-1][1]=max(right, ans[ans.size()-1][1]);
            }
        }
        return ans;
    }
};