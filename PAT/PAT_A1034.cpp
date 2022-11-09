#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using std::sort;
using std::vector;
using std::map;

struct node{
    char name[4];
    int time=0;//通话时间
    int cnt;//帮派人数
    node():name(""),time(0),cnt(0){}
    bool operator<(const node& item)const{
        return strcmp(name, item.name)<0;
    }
};

struct cmp1{
    bool operator()(const char* s1, const char* s2)const{
        return strcmp(s1,s2)<0;
    }
};

int N,K;//最多N条边，所以最多2N个点
map<char*, int, cmp1> mp;
vector<node> nodes;
vector<vector<int>> edges;//最大1000使用邻接矩阵
vector<int> res;
vector<bool> visited;


struct cmp2{
    bool operator()(int i, int j)const{
        return nodes[i]<nodes[j];
    }
};

void dfs(int i, int& sum, int& cnt, int& head){
    visited[i]=true;
    for(int j=0;j<N;j++){
        if(edges[i][j]>0){//存在边
            // 先加权重，遍历每一条边防止漏加
            nodes[i].time+=edges[i][j];
            nodes[j].time+=edges[i][j];
            sum+=edges[i][j];
            head=nodes[i].time>nodes[head].time?i:head;
            head=nodes[j].time>nodes[head].time?j:head;
            // 然后删除边，防止多加
            edges[i][j]=edges[j][i]=0;//删除边

            // 遍历每一个点
            if(!visited[j]){
                cnt++;
                dfs(j, sum, cnt, head);
            }
        }
    }
}

int main(){
    scanf("%d %d",&N,&K);
    visited.assign(2*N, false);
    nodes.assign(2*N, node());
    edges.assign(2*N, vector<int>(2*N, 0));
    char n1[4];
    char n2[4];
    int id1, id2, time, nodeNum=0;
    for(int i=0;i<N;i++){
        scanf("%s %s %d",n1,n2,&time);
        if(mp.count(n1)>0){
            id1=mp[n1];
        }else{
            id1=nodeNum++;
            strcpy(nodes[id1].name, n1);
            mp[nodes[id1].name]=id1;
        }
        if(mp.count(n2)>0){
            id2=mp[n2];
        }else{
            id2=nodeNum++;
            strcpy(nodes[id2].name, n2);
            mp[nodes[id2].name]=id2;
        }
        edges[id1][id2]+=time;
        edges[id2][id1]+=time;
    }
    // dfs travel
    for(int i=0;i<nodeNum;i++){
        if(nodes[i].time==0){//未被访问过
            int sum=0, cnt=1, head=i;//通话总时长,帮派人数,老大
            dfs(i, sum, cnt, head);
            if(sum>K && cnt>2){
                res.push_back(head);
                nodes[head].cnt=cnt;//只要在老大那里记录帮派人数就可以了
            }
        }
    }

    // output
    printf("%lu\n", res.size());
    sort(res.begin(), res.end(), cmp2());
    for(int& head:res){
        printf("%s %d\n", nodes[head].name, nodes[head].cnt);
    }
    return 0;
}
