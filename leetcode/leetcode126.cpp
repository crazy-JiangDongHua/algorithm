class Solution {
public:
    unordered_map<string, int> nodes;//nodes
    vector<string> newWordList;
    vector<vector<int> > edges;
    vector<vector<int> > fathers; 
    int nodeNums=0;

    bool addNode(const string& s){
        if(!nodes.count(s)){
            nodes[s]=nodeNums++;
            newWordList.emplace_back(s);
            edges.emplace_back();
            fathers.emplace_back();
            return true;
        }
        return false;
    }

    void addEdges(string& s){
        //必须加，否则beginword如果在wordlist里面，或者wordlist里面有重复
        //就会导致孩子序列重复，导致路径数量翻倍。
        if(!addNode(s))return; 
        int id1=nodes[s];
        for(char& c:s){
            char tmp=c;
            c='*';
            addNode(s);
            int id2=nodes[s];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            c=tmp;
        }
    }

    void gen_path(vector<vector<string>>& res, vector<string>& path,
                int id, int beginId){//dfs
        if(id==beginId){
            res.emplace_back(path);
            reverse(res.back().begin(), res.back().end());
        }else{
            for(int& f:fathers[id]){
                for(int& g:fathers[f]){
                    path.emplace_back(newWordList[g]);
                    gen_path(res, path, g, beginId);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(string& s:wordList)
            addEdges(s);
        addEdges(beginWord);
        vector<vector<string>> res;
        if(!nodes.count(endWord))
            return res;
        
        queue<int> q;
        int beginId=nodes[beginWord], endId=nodes[endWord];
        q.push(beginId);
        vector<int> dis(nodes.size(), INT_MAX);
        dis[beginId]=0;

        while(!q.empty()){
            bool isfound=false;
            for(int i=0,s=q.size();i<s;i++){
                int id=q.front();q.pop();
                for(int& child: edges[id]){
                    if(dis[child]==INT_MAX){
                        //还没被访问过
                        dis[child]=dis[id]+1;
                        fathers[child].push_back(id);
                        q.push(child);

                    }else if(dis[child]==dis[id]+1){
                        fathers[child].push_back(id);
                    }// 如果小于不用处理，不可能大于。

                    if(child==endId)isfound=true;
                }
            }
            if(isfound)break;
        }
        vector<string> path;
        path.emplace_back(newWordList[endId]);
        gen_path(res, path, endId, beginId);
        return res;
    }
};










