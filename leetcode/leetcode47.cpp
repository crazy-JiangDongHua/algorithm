class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        bool hashtabel[8]; //现在是否被使用
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
        //可以通过对数组进行预排序，使得重复元素挨在一起，判断的时候和前面元素一样，且前面元素现在没有使用，那就是重复，跳过。
        //这样就可以省去vis
        bool vis[21]; //之前有没有被使用
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<nums.size();i++)
        {
            if(!hashtabel[i] && !vis[nums[i]+10])
            {
                // 可以使用交换操作去掉标记数组
                temp.push_back(nums[i]);
                hashtabel[i] = true;
                vis[nums[i]+10] = true;
                dfs(temp, nums, res, hashtabel);
                temp.pop_back();
                hashtabel[i] = false;
            }
        }
    }
};
