// 方法三 Bellman-Ford算法
#include <cstdio>
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

struct edge{
    int v,w;
    edge(){}
    edge(int v, int w):v(v),w(w){}
};

const int INF=0x3fffffff;
int n,m,c1,c2;
vector<int> dis;
vector<vector<edge>> edges;
vector<int> reward;//每个城市救援团队数量
vector<int> r;//最多的救援数量
vector<int> num;//记录最短路径数量
vector<unordered_set<int>> pre;//前驱

void bf(int s){
    dis[s]=0;
    r[s]=reward[s];
    num[s]=1;
    for(int i=1;i<n;i++){
        int cnt=0;
        for(int u=0;u<n;u++){
            for(edge& e:edges[u]){
                if(dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    r[e.v]=r[u]+reward[e.v];
                    num[e.v]=num[u];
                    pre[e.v].clear();
                    pre[e.v].insert(u);
                    cnt++;
                }else if(dis[u]+e.w==dis[e.v]){
                    if(r[e.v]<r[u]+reward[e.v]){
                        r[e.v]=r[u]+reward[e.v];
                    }
                    pre[e.v].insert(u);
                    num[e.v]=0;
                    for(const int& p:pre[e.v]){
                        num[e.v]+=num[p];
                    }
                    cnt++;
                }
            }
        }
        if(cnt==0)return;
    }
}

int main(){
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    dis.assign(n, INF);
    edges.assign(n, vector<edge>());
    reward.assign(n, 0);
    r.assign(n, 0);
    num.assign(n, 0);
    pre.assign(n, unordered_set<int>());
    for(int i=0;i<n;i++){
        scanf("%d", &reward[i]);
    }
    int s,t,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&s,&t,&w);
        edges[s].emplace_back(t,w);
        edges[t].emplace_back(s,w);
    }
    bf(c1);
    printf("%d %d",num[c2],r[c2]);
    return 0;
}