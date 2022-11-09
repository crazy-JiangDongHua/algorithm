前两节复习了图的基础知识，从这一节开始，每一节都开始介绍一个图的经典问题。
本节介绍的是经典中的经典，最短路径问题。

最短路径问题具体定义为：给定一个图G(V,E)，求从一个起点到终点的路径，使得路径上的边权和最小。最短路径问题，分为单源最短路径和多源最短路径，单源，就是求给定起点到其他点的最短路径，多源就是求所有点两两之间的最短路径。

### 1. Dijkstra算法

Dijkstra算法路径用来解决单源最短路径。其策略为：
1. 每次从未访问的结点集合中，选择距离起点s最短的一个访问（记为u）。
2. 之后令u为中介点，优化起点s与所有u能到达的顶点之间的最短距离。

邻接矩阵版本实现，适合顶点数比较少的时候（小于1000）。外层循环$O(V)$次，内层循环，找最小需要$O(V)$，每次优化需要$O(V)$，所以总的时间复杂度为$O(V^2)$
```c++
int MAXN=1000;
int INF=0x3fffffff; //不用0x7fffffff是因为距离相加就溢出了
int n;//实际n个结点
vector<int> dis(n, INF);
vector<bool> visited(n, false);
vector<vector<int>> g;//邻接矩阵
void djistra(int s){// s为起点
    d[s]=0;
    for(int i=0;i<n;i++){//n个顶点要被标记为已访问
        // 从未访问的结点集合中，选择距离起点s最短的一个访问
        int u=-1, mindis=INF;
        for(int j=0;i<n;i++){
            if(!visited[j] && dis[j]<mindis){
                u=j;mindis=dis[j];
            }
        }
        // 说明剩下的顶点都是到达不了的，与s不连通
        if(mindis==INF)return;
        visited[u]=true;
        // 优化u能到达的，且没访问过的点
        for(int j=0;j<n;j++){
            if(!visited[j] && dis[u]+g[u][j]<dis[j]){
                dis[j]=dis[u]+g[u][j];
            }
        }
    }
}
```

邻接表版本实现。外层循环$O(V)$次，内层循环，找最小需要$O(V)$，优化就是遍历所有的边，加在一起就是$O(E)$次（e是边的数量），所以总的时间复杂度为$O(V^2+E)$
```c++
int MAXN=1000;
int INF=0x3fffffff; //不用0x7fffffff是因为距离相加就溢出了
int n;//实际n个结点
vector<int> dis(n, INF);
vector<bool> visited(n, false);
struct edge{
    int v,w;//边指向的点和边权
}
vector<vector<edge>> g;//邻接表
void djistra(int s){// s为起点
    d[s]=0;
    for(int i=0;i<n;i++){//n个顶点要被标记为已访问
        // 从未访问的结点集合中，选择距离起点s最短的一个访问
        int u=-1, mindis=INF;
        for(int j=0;i<n;i++){
            if(!visited[j] && dis[j]<mindis){
                u=j;mindis=dis[j];
            }
        }
        // 说明剩下的顶点都是到达不了的，与s不连通
        if(mindis==INF)return;
        visited[u]=true;
        
        // 从这里开始不一样

        // 优化u能到达的，且没访问过的点
        for(edge& e:g[u]){
            if(!visited[e.v] && dis[u]+e.w<dis[e.v]){
                dis[e.v]=dis[u]+e.w;
            }
        }
    }
}
```

有两个需要注意的地方：
1. 有负权边是，dijstra算法会出错。
2. 时间复杂度优化，最外层循环n次是少不了的，但是内层中寻找距离最小顶点时可以用堆来优化的，实现如下。时间复杂度方面，外层循环，因为每个结点可能重复入队，最坏情况下，时间复杂度为$O(E)$。内层循环，求距离最小结点时间复杂度为$O(\log E)$。优化就是遍历所有的边，加在一起就是$O(E)$次。因此时间复杂度为$O(E\log E)$。一般情况下$E=\theta (V)$使用堆会比普通写法快非常多。但是假如是完全图，$E=\theta (V^2)$，那么最坏情况下，时间复杂度为$V^2\log V^2$。不过一般都不会是完全图，而且恰好满足最坏情况hhh。
```c++
int MAXN=1000;
int INF=0x3fffffff; //不用0x7fffffff是因为距离相加就溢出了
int n;//实际n个结点
vector<int> dis(n, INF);
vector<bool> visited(n, false);
struct edge{
    int v,w;//边指向的点和边权
}
vector<vector<edge>> g;//邻接表
struct node{
    int v,dis;
    node(int v, int dis):v(v),dis(dis){}
    //要用小顶堆
    bool operator<(const node& item)const{
        return dis>item.dis;
    }
}
void djistra(int s){// s为起点
    d[s]=0;
    priority_queue<node> pq;
    pq.emplace(s, 0);
    while(!pq.empty()){
        // 从未访问的结点集合中，选择距离起点s最短的一个访问
        // 此处使用优先级队列优化
        node n=p.top();p.pop();
        // 已经访问过，说明已经找到最短路，不需要在入队
        if(visited[n.v])
            continue;
        
        // 找到最短路径
        visited[n.v]=true;

        // 优化u能到达的，且没访问过的点
        for(edge& e:g[n.v]){
            if(!visited[e.v] && dis[n.v]+e.w<dis[e.v]){
                dis[e.v]=dis[u]+e.w;
                pq.emplace(e.v, dis[e.v]);
            }
        }
    }
}
```

要求具体路径的话，只需要设置一个前驱数组，然后在优化的时候记录就好了。
```c++
vector<int> pre(n,0);
// 每个结点的前驱初始化为自己
for(int i=0;i<n;i++)
    pre[i]=i;

// 优化时记录
if(!visited[e.v] && dis[u]+e.w<dis[e.v]){
    dis[e.v]=dis[u]+e.w;
    //令e.v的前驱为u
}
```
然后用递归求解
```c++
void dfs(int i){
    if(i==pre[i]){
        printf("%d ", i);
        return;
    }
    dfs(pre[i]);
    printf("%d ", i);
}
```

但是显然考试不会这么直白，不然人人都满分了。很多时候最短路径有很多条，一般都会加一个第二标尺（第一标尺为距离），常见的形式有：
1. 给每条边再加一个边权（比如说花费）。然后求在最短路径有多条时选花费之和最小的。
2. 给每个点再加一个点权（比如说奖励）。然后求在最短路径有多条时选奖励之和最大的。
3. 直接求最短路径的条数。

这三种都是可以通过增加一个数组，然后修改优化部分解决。
1. 新增边权。用`cost[u][v]`表示从`u`到`v`的花费。新增一个数组`c[]`，用`c[u]`表示从`s`到`u`在满足距离最小的情况下最小的花费。初始化时`c[s]=0`，其余均为`INF`。优化部分代码修改如下
```c++
for(edge& e:g[u]){
    if(!visited[e.v]){
        if(dis[u]+e.w<dis[e.v]){ //可以优化最短距离
            dis[e.v]=dis[u]+e.w;
            // 必须跟着优化，不管是否变大
            c[e.v]=c[u]+cost[u][e.v];
        }
        else if(dis[u]+e.w==dis[e.v] && c[u]+cost[u][e.v]<c[e.v]){ //距离相等但是第二尺度可以更优
            c[e.v]=c[u]+cost[u][e.v];
        }
    }
}
```
2. 新增点权。用`reward[u]`表示`u`的奖励。新增一个数组`r[]`，用`r[u]`表示从`s`到`u`在满足距离最小的情况下最大的奖励。初始化时`r[s]=reward[s]`，其余均为`0`。优化部分代码修改如下
```c++
for(edge& e:g[u]){
    if(!visited[e.v]){
        if(dis[u]+e.w<dis[e.v]){ //可以优化最短距离
            dis[e.v]=dis[u]+e.w;
            // 必须跟着优化，不管是否变大
            r[e.v]=r[u]+reward[e.v];
        }
        else if(dis[u]+e.w==dis[e.v] && r[u]+reward[e.v]>r[e.v]){ //距离相等但是第二尺度可以更优
            r[e.v]=r[u]+reward[e.v];
        }
    }
}
```
3. 计算最短路径的数量。只需要新增一个数组`num[]`，用`num[u`表示从`s`到`u`最短路径的数量。初始化时，`num[s]=1`，其余为`0`。优化部分代码修改如下。
```c++
for(edge& e:g[u]){
    if(!visited[e.v]){
        if(dis[u]+e.w<dis[e.v]){ //可以优化最短距离
            dis[e.v]=dis[u]+e.w;
            num[e.v]=num[u];
        }
        else if(dis[u]+e.w==dis[e.v]){ //距离相等
            num[e.v]+=num[u];
        }
    }
}
```

如果要求真的特别多的话，可以先记录下俩所有最短路径，然后通过dfs的方法去找满足条件的最优解。


### 2. Bellman-Ford算法和SPFA算法
有负权边的图，dijstra算法就会失效，而Bellman-Ford算法可以有效解决这个问题。

Bellman-Ford算法思路非常简单，就是通过边不断的进行松弛操作，有就是指dijstra里面的优化操作。对每一条边，我们都去看是否能优化起点到边指向结点的距离。这样迭代V-1轮。如果没有负权环，那么就找到最短路径，起点到结点的最短距离不能再被优化，如果还能优化说明存在负权环。

使用邻接表实现时间复杂度为$O(VE)$，使用邻接矩阵实现时间复杂度为$O(V^3)$。邻接表实现如下：
```c++
struct edge{
    int v,w;
}
const int INF=0x3fffffff;
int n;//结点数量
vector<vector<edge>> edges;//邻接表
vector<int> dis(n, INF);

bool bellman(int s){// s为源点 
    dis[s]=0;
    for(int i=1;i<n;i++){
        int cnt=0;
        for(int u=0;u<n;u++){
            for(edge& e:edges[u]){
                if(dis[u]+e.w<dis[e.v])
                    dis[e.v]=dis[u]+e.w;//松弛操作
                    cnt++;
            }
        }
        if(cnt==0)break;//没法优化了就提前退出
    }
    // 判断是否存在负权环
    for(int u=0;u<n;u++){
        for(edge& e:edges[u]){
            if(dis[u]+e.w<dis[e.v])
                return false;// 还能优化，有负权环
        }
    }
    return true;
}
```

如果存在第二标尺，bellman-ford算法和之前计算是一样的。但是对于计算最短路径条数，bf算法可能会重复访问之前访问过的结点，所以不止需要新增一个`num[]`数组，还需要用`unordered_set<int> pre[]`记录每一个结点的前驱。优化部分代码修改如下
```c++
for(edge& e:g[u]){
    if(dis[u]+e.w<dis[e.v]){ //可以优化最短距离
        dis[e.v]=dis[u]+e.w;
        num[e.v]=num[u];
        pre[e.v].clear();
        pre[e.v].insert(u);
    }
    else if(dis[u]+e.w==dis[e.v]){ //距离相等
        pre[e.v].insert(u);
        //重新统计
        num[e.v]=0;
        for(const int& p:pre[e.v]){
            num[e.v]+=num[p];
        }
    }
}
```

BF算法的一大问题就是时间复杂度太高。一种常见的优化算法时SPFA（short path faster algorithm）。显然我们不需要对所有的边做松弛操作，只需要对`dis[u]`改变了的结点`u`的所有边做松弛操作。一般我们通过队列来存储结点`u`。这种算法的期望时间复杂度为$O(kE)$，一般k为2。比经过堆优化的dijstra优化还快。但是如果存在源点可达的负权环，则退化成$O(VE)$。代码实现如下：
```c++
struct edge{
    int v,w;
}
const int INF=0x3fffffff;
int n;//结点数量
vector<vector<edge>> edges;//邻接表
vector<int> dis(n, INF);
vector<int> num(n, 0);//各个结点入队次数，如果入队次数大于n-1，则说明有源点可达负权环
vector<bool> inq(n, false);//结点是否在队列中
bool spfa(int s){// s为源点
    dis[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;
    num[s]=1;
    while(!q.empty){
        int u=q.front();q.pop();
        inq[u]=false;
        for(edge& e:edges[u]){
            if(dis[u]+e.w<dis[e.v]){
                dis[e.v]=dis[u]+e.w;
                if(!inq[e.v]){
                    q.push(e.v);
                    inq[e.v]=true;
                    num[e.v]++;
                    // 有源点可达负权环
                    if(num[e.v]>n-1)
                        return false;
                }
            }
        }
    }
    return true;
}
```

**careful！！！** 如果存在第二标尺，且一个结点的最短路径没有改变，第二标尺发生了改变，那么该结点也应该重新加入队列，再次松弛，但是不应该计入入队次数去判断负权环。如果只有这种更新，在bf中也不应该提前结束遍历。

### 3. Floyd算法
Floyd算法用来求全源最短路径，是一种dp算法，时间复杂度为$O(V^3)$，因此适合结点数不多的图，所以可以使用邻接矩阵实现。

Floyd算法可以算带负权边的图，但是不能有负权环。

Floyd算法基于一个很简单的思想，如果存在一个中介点`k`，使得从`i`到`j`的路径变短，那么就采用`k`作为`i`和`j`的中介点，即`dis[i][j]=min(dis[i][k]+dis[k][j], dis[i][j])`，从0-1遍历`k`，算法实现如下：
```c++
int n;//结点个数
const int INF=0x3fffffff;
vector<vector<int>> dis;//初始化为邻接矩阵, dis[i][i]=0
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j], dis[i][j]);
            }
        }
    }
}
```

对于没有源点可达负权环的连通图而言，任意两点之间的最短路径必然不存在重复结点，而floyd算法相当于在起点和终点中不停的插入其他结点，最后得到最短路径。


练习：
1. PAT A1003 Emergency：单源最短路径+第二标尺，一遍dijstra过，或者bf，或者spfa。
2. PAT A1030 Travel Plan：单源最短路径+第二标尺，dijstra+dfs。