最小生成树问题是指，给定一个无向图G(V,E)，求图G的一个子图T，T是一棵树，这棵树拥有图G所有的顶点，且边权之和最小。最小生成树可以不唯一，但是边权之和一定唯一。求解方法主要有两种，prim算法和kruskal算法，均采用了贪心的思想。

1. prim算法
prim算法的基本思想是维护一个已访问结点集合S，然后每次选择未访问顶点集合V-S中距离S最近的那个顶点u访问，然后利用u去优化其他未访问结点到S的距离。这个思路其实和dijstra非常像，只不过维护的距离，从结点到源点s的距离，变成了结点到集合S的距离。
邻接矩阵实现如下，时间复杂度分析与dijstra算法相同，$O(V^2)$
```c++
const int INF=0x3ffffff;
int n;//结点数量
vector<vector<int>> g;//邻接矩阵
vector<int> dis(n, INF);//到已访问结点集合
vector<bool> visited(n, false);//是否访问

int prim(){ //默认使用0号为初始点，函数返回最小生成树的边权之和
    dis[0]=0;
    visited[0]=true;
    int ans=0;
    for(int i=0;i<n;i++){
        // 选取未访问结点中dis最小的
        int u=-1, mindis=INF;
        for(int j=0;j<n;j++){
            if(!visited[j] && dis[j]<mindis){
                u=j;
                mindis=dis[j];
            }
        }
        if(u==-1)return -1;//找不到最小，说明剩下的顶点和S不连通
        visited[u]=true;
        ans+=dis[u];
        for(int v=0;v<n;v++){
            if(!visited[v] && g[u][v]<dis[v]){
                dis[v]=g[u][v];
            }
        }
    }
    return ans;
}
```

邻接表实现版本如下，时间复杂度分析与dijstra算法相同，$O(V^2+E)$
```c++
struct edge{
    int v,w;
}
const int INF=0x3ffffff;
int n;//结点数量
vector<vector<edge>> g;//邻接表
vector<int> dis(n, INF);//到已访问结点集合
vector<bool> visited(n, false);//是否访问

int prim(){ //默认使用0号为初始点，函数返回最小生成树的边权之和
    dis[0]=0;
    visited[0]=true;
    int ans=0;
    for(int i=0;i<n;i++){
        // 选取未访问结点中dis最小的
        int u=-1, mindis=INF;
        for(int j=0;j<n;j++){
            if(!visited[j] && dis[j]<mindis){
                u=j;
                mindis=dis[j];
            }
        }
        if(u==-1)return -1;//找不到最小，说明剩下的顶点和S不连通
        visited[u]=true;
        ans+=dis[u];
        for(edge& e:g[u]){
            if(!visited[e.v] && g[u][e.v]<dis[e.v]){
                dis[e.v]=g[u][e.v];
            }
        }
    }
    return ans;
```

寻找距离最小也可以用堆优化，时间复杂度为$E\log E$，实现如下
```c++
struct edge{
    int v,w;
}
struct node{
    int v,dis;
    node(){}
    node(int v, int dis):v(v),dis(dis){}
    bool operator<(const node& item)const{
        return dis>item.dis;
    }
}
const int INF=0x3ffffff;
int n;//结点数量
vector<vector<edge>> g;//邻接表
vector<int> dis(n, INF);//到已访问结点集合
vector<bool> visited(n, false);//是否访问

int prim(){ //默认使用0号为初始点，函数返回最小生成树的边权之和
    dis[0]=0;
    visited[0]=true;
    int ans=0;
    priority_queue<node> pq;
    pq.emplace(0,0);
    while(!pq.empty()){
        // 选取未访问结点中dis最小的
        node n=pq.top();pq.pop();
        int u=n.v;
        if(visited[u])continue;//已经找到最短距离
        if(dis[u]==INF)return -1;//说明剩下的结点和S不连通
        visited[u]=true;
        ans+=dis[u];
        for(edge& e:g[u]){
            if(!visited[e.v] && g[u][e.v]<dis[e.v]){
                dis[e.v]=g[u][e.v];
                pq.emplace(e.v, dis[e.v]);
            }
        }
    }
    return ans;
```

2. kruskal算法
kruskal算法的思想更加简单：
1. 对所有边按照边权从小到达排序
2. 从小到达测试所有边，如果当前测试的边所连接的两个顶点不在同一个连通快内，则把这条测试边加入生成树，否则舍弃
3. 重复2，直到加入了V-1条边，如果结束时边数量小于V-1，说明有结点不连通
```c++
int n,m;//结点数量，边的数量
const int INF=0x3fffffff;
struct edge{
    int u,v,w;//u->v
    bool operator<(const edge& item)const{
        return w<item.w;
    }
};
vector<edge> edges;//所有边
vector<int> father(n, 0);//并查集
int find(int x){
    return x==father[x]?x:father[x]=find(father[x]);
}
int kruskal(){//默认使用0号为初始点，函数返回最小生成树的边权之和
    // 初始化并查集
    for(int i=0;i<n;i++)
        father[i]=i;
    int ans=0, edgeNum=0;
    sort(edges.begin(), edges.end());
    for(int i=1;i<m;i++){
        int fau=find(edges[i].u);
        int fav=find(edges[i].v);
        if(fau!=fav){
            if(edges[i].w==INF)break;//不连通了
            ans+=edges[i].w;
            edgeNum++;
            father[fau]=fav;
            if(edgeNum==n-1)break；//已经找到最小生成树了
        }
    }
    if(edgeNum != n-1)return -1;
    return ans;
}
```

kruskal算法时间复杂度为$O(E\log E)$。所以边多（稠密图）用普通邻接表实现的prim，边少（稀疏图）用kruskal或者堆优化邻接表prim
