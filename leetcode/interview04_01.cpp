// 方法一 dfs
class Solution {
private:
    bool findWhetherExistsPath(vector<vector<int>>& edges, int start, int target){
        vector<int> visited(edges.size(), 0);
        return findWhetherExistsPath(edges, visited, start, target);
    }
    bool findWhetherExistsPath(vector<vector<int>>& edges, vector<int>& visited, int cur, int target){
        if(cur==target)
            return true;
        visited[cur]=1;
        for(int& node:edges[cur]){
            if(visited[node]==0 && findWhetherExistsPath(edges, visited, node, target))
                return true;
        }
        return false;
    }
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // 邻接表
        vector<vector<int>> edges(n, vector<int>());
        for(vector<int>& edge:graph){
            edges[edge[0]].push_back(edge[1]);
        }
        return findWhetherExistsPath(edges, start, target);
    }
};

// 方法二 bfs
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start==target)
            return true;
        // 邻接表
        vector<vector<int>> edges(n, vector<int>());
        for(vector<int>& edge:graph){
            edges[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int& node:edges[cur]){
                if(visited[node]==0){
                    if(node==target)
                        return true;
                    q.push(node);
                    visited[node]=1;
                }
            }
        }
        return false;
    }
};