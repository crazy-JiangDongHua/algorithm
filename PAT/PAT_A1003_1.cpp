// 方法一 普通dijstra
#include <cstdio>
#include <vector>
using std::vector;

struct edge{
    int v,w;
    edge(){}
    edge(int v, int w):v(v),w(w){}
};

const int INF=0x3fffffff;
int n,m,c1,c2;
vector<int> dis;
vector<int> visited;
vector<vector<edge>> edges;
vector<int> reward;//每个城市救援团队数量
vector<int> r;//最多的救援数量
vector<int> num;//记录最短路径数量

void dijstra(int s){
    dis[s]=0;
    r[s]=reward[s];
    num[s]=1;
    for(int i=0;i<n;i++){
        int u=-1, mindis=INF;
        for(int j=0;j<n;j++){
            if(!visited[j] && dis[j]<mindis){
                u=j;
                mindis=dis[j];
            }
        }
        if(u==-1)return;//不连通了
        visited[u]=true;
        for(edge& e:edges[u]){
            if(!visited[e.v]){
                if(dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    r[e.v]=r[u]+reward[e.v];
                    num[e.v]=num[u];
                }else if(dis[u]+e.w==dis[e.v]){
                    if(r[e.v]<r[u]+reward[e.v]){
                        r[e.v]=r[u]+reward[e.v];
                    }
                    num[e.v]+=num[u];
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    dis.assign(n, INF);
    visited.assign(n, false);
    edges.assign(n, vector<edge>());
    reward.assign(n, 0);
    r.assign(n, 0);
    num.assign(n, 0);
    for(int i=0;i<n;i++){
        scanf("%d", &reward[i]);
    }
    int s,t,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&s,&t,&w);
        edges[s].emplace_back(t,w);
        edges[t].emplace_back(s,w);
    }
    dijstra(c1);
    printf("%d %d",num[c2],r[c2]);
    return 0;
}