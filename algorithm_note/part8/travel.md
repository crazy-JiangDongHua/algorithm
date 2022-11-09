首先介绍两个概念：
连通分量：在无向图中，若两个顶点之间可以互相到达，则称两点连通。如果图G任意两点都连通，那么称图G为连通图。否则称图G为非连通图，且称其中的极大连通子图为连通分量

强连通分量：在有向图中，若两个顶点可以各自通过一条有向路径到达另外一个顶点，则称两顶点强连通。如果图G任意两个顶点都强连通，则称图G为强连通图。否则则称图G为非强连通图，且称其中的极大强连通子图为强连通分量。

称连通分量和强连通分量为连通块，那么遍历图也就是取遍历每个连通块，而每个连通块需要进行一次dfs/bfs

深度优先搜索遍历图
```c++
G[V,G];//可以用邻接矩阵或者邻接表
bool visit[n];
void dfs(int i){
    visit[i]=true;
    for(int j:从i出发能到达的所有结点){
        if(!visit[j])
            dfs(j);
    }
}
void dfsTravel(){
    for(v:V){
        if(!visit[v]){
            dfs(v);
        }
    }
}
```

采用广度优先搜索遍历图
```c++
G[V,G];//可以用邻接矩阵或者邻接表
bool visit[n];
void dfs(int i){
    queue<int> q;
    q.push(i);
    visit[i]=true;
    while(!q.empty()){
        i=q.front();q.pop();
        for(int j:从i出发能到达的所有结点){
            if(!visit[j])
                q.push(j);
        }
    }
}
void dfsTravel(){
    for(v:V){
        if(!visit[v]){
            bfs(v);
        }
    }
}
```

练习：
1. leetcode 133 克隆图：dfs or bfs。
2. PAT A1034 Head of a Gang：把人看作结点，通话看作边，通话时间是边权，一个人全部的通话时间是点权。我们需要求所有的点权，以及一个连通分量的边权和。点权可以简单遍历点去求，但是边权为了不遗漏，需要在遍历点之前，每发现一条边就加上，但是这样又可能会被多算，所以加了之后就删除这条边。
3. PAT A1076 Forwards on Weibo：典型的bfs