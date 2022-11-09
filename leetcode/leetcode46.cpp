class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        bool hashtabel[21];
        memset(hashtabel, 0, sizeof(hashtabel));
        vector<vector<int>> res;
        vector<int>temp;
        dfs(temp, nums, res, hashtabel);
        return res;
    }

    void dfs(vector<int>& temp, const vector<int>& nums, vector<vector<int>>& res, bool hashtabel[])
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(vector<int>::const_iterator it=nums.begin();it!=nums.end();it++)
        {
            if(!hashtabel[*it+10])
            {
                // 可以使用交换操作去掉标记数组
                temp.push_back(*it);
                hashtabel[*it+10] = true;
                dfs(temp, nums, res, hashtabel);
                temp.pop_back();
                hashtabel[*it+10] = false;
            }
        }
    }


};
