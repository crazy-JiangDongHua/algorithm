// bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        vector<Node*> graph(101, nullptr);
        graph[node->val]=new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            node=q.front();q.pop();
            for(Node*& nb : node->neighbors){
                if(graph[nb->val]==nullptr){
                    graph[nb->val]=new Node(nb->val);
                    q.push(nb);
                }
                graph[node->val]->neighbors.push_back(graph[nb->val]);
            }
        }
        return graph[1];
    }
};

//dfs
class Solution {
private:
    vector<Node*> graph;
public:
    Solution(){
        graph.assign(101, nullptr);
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        if(graph[node->val]==nullptr){
            graph[node->val]=new Node(node->val);        
            for(Node*& nb:node->neighbors){
                graph[node->val]->neighbors.push_back(cloneGraph(nb));
            }
        }
        return graph[node->val];
    }
};