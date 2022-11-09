#include <cstdio>
#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;

struct edge{
    int v,w;
    edge(){}
    edge(int v, int w):v(v),w(w){}
};

struct node{
    int v,dis;
    node(){}
    node(int v,int dis):v(v),dis(dis){}
    bool operator<(const node& item)const{
        return dis>item.dis;
    }
};


const int INF=0x3fffffff;
int n,m,c1,c2;
vector<int> dis;
vector<int> visited;
vector<vector<edge>> edges;
vector<vector<int>> cost;
vector<vector<int>> pre;

void dijstra(int s){
    dis[s]=0;
    pre[s].emplace_back(s);
    priority_queue<node> pq;
    pq.emplace(s, 0);
    while(!pq.empty()){
        node n=pq.top();pq.pop();
        int u=n.v;
        if(visited[u])continue;;//已经找到最短路径了
        visited[u]=true;
        for(edge& e:edges[u]){
            if(!visited[e.v]){
                if(dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    pq.emplace(e.v, dis[e.v]);
                    pre[e.v].clear();
                    pre[e.v].emplace_back(u);
                }else if(dis[u]+e.w==dis[e.v]){
                    pre[e.v].emplace_back(u);
                }
            }
        }
    }
}

void dfs(int v, vector<int>& res, vector<int>& tmp, int sum, int& minc){
    if(v==c1){
        tmp.emplace_back(v);
        if(sum<minc){
            res=tmp;
            minc=sum;
        }
        tmp.pop_back();
        return;
    }
    tmp.emplace_back(v);
    for(int& p:pre[v]){
        dfs(p, res, tmp, sum+cost[v][p], minc);
    }
    tmp.pop_back();
}

int main(){
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    dis.assign(n, INF);
    visited.assign(n, false);
    edges.assign(n, vector<edge>());
    pre.assign(n, vector<int>());
    cost.assign(n, vector<int>(n, INF));//为方便使用邻接矩阵存储
    int s,t,w,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&s,&t,&w,&c);
        edges[s].emplace_back(t,w);
        edges[t].emplace_back(s,w);
        cost[s][t]=cost[t][s]=c;
    }
    dijstra(c1);
    vector<int> res, tmp;
    int minc=INF;
    dfs(c2, res, tmp, 0, minc);
    for(int i=res.size()-1;i>=0;i--)
        printf("%d ", res[i]);
    printf("%d %d", dis[c2], minc);
    return 0;
}