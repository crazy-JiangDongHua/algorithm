class Solution {
public:

    vector<vector<int>> edges;
    unordered_map<string, int>hash;
    int nodeNums=0;

    bool addWord(string& s){
        if(!hash.count(s)){
            hash[s] = nodeNums++;
            edges.emplace_back();
            return true;
        }
        return false;
    }

    void addEdges(string& s){
        //必须加，否则beginword如果在wordlist里面，或者wordlist里面有重复
        //就会导致孩子序列重复，导致路径数量翻倍。
        if(!addWord(s))return;
        int id1=hash[s];
        for(char& c : s){
            char tmp=c;
            c = '*';
            addWord(s);
            int id2=hash[s];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            c = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string& s:wordList)
            addEdges(s);
        addEdges(beginWord);

        if(!hash.count(endWord))
            return 0;
        
        int beginId=hash[beginWord], endId=hash[endWord];
        vector<int> dis_begin(nodeNums, INT_MAX), dis_end(nodeNums, INT_MAX);
        dis_begin[beginId]=0;dis_end[endId]=0;
        queue<int> q_begin, q_end;
        q_begin.push(beginId);
        q_end.push(endId);
        while(!q_begin.empty() && !q_end.empty()){
            for(int i=0,n=q_begin.size();i<n;i++){
                int id=q_begin.front();q_begin.pop();
                if(dis_end[id] != INT_MAX)
                    return (dis_begin[id]+dis_end[id])/2+1;
                for(int& j:edges[id]){
                    if(dis_begin[j]==INT_MAX){
                        q_begin.push(j);
                        dis_begin[j]=dis_begin[id]+1;
                    }
                }
            }
            for(int i=0,n=q_end.size();i<n;i++){
                int id=q_end.front();q_end.pop();
                if(dis_begin[id] != INT_MAX)
                    return (dis_begin[id]+dis_end[id])/2+1;
                for(int& j:edges[id]){
                    if(dis_end[j]==INT_MAX){
                        q_end.push(j);
                        dis_end[j]=dis_end[id]+1;
                    }
                }
            }
        }
        return 0;
    }

};