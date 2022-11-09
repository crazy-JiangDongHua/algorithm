class Solution {
private:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int, int>& b){
            return a.second<b.second;
        }
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 所有的天际线都产生于建筑的边界
        vector<int> bounds;
        for(vector<int>& building:buildings){
            bounds.emplace_back(building[0]);
            bounds.emplace_back(building[1]);
        }
        // 建筑边界排序，从左到右
        sort(bounds.begin(), bounds.end());
        // first表示右边界，second表示左边界
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int index=0;
        vector<vector<int>> res;
        for(int& bound:bounds){
            // 对于所有左边界在bound左边的建筑，他们都可能覆盖bound
            // 也就是说他们的右边界都有可能在bound右边，会影响bound处的高度计算
            while(index<buildings.size() && buildings[index][0]<=bound){
                pq.emplace(buildings[index][1], buildings[index][2]);
                index++;
            }
            // 对于右边界在bound左边的建筑，他们不会影响bound及其之后边界线的高度计算，所以弹出
            // 但是不是所有不符合的建筑马上弹出，我们只需要保证pq队头的建筑的高度是我们所需要的就行了
            // 这是一种叫延时删除的技巧。
            while(!pq.empty() && pq.top().first<=bound)
                pq.pop();
            
            int h=pq.empty()?0:pq.top().second;
            // 如果和上一个天际线的高度相同，说明被同一个建筑覆盖，不是需要的天际线
            if(res.empty() || (*(res.end()-1))[1]!=h){
                res.push_back({bound, h});
            }
        }
        return res;
    }
};