#include <cstdio>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

int n,l,k,q;
vector<vector<int>> g;

int bfs(int i){
    vector<int> visited(n+1, false);
    queue<int> q;
    q.push(i);
    visited[i]=true;
    int cnt=0, l1=0;
    while(!q.empty() && l1<l){
        for(int k=0,s=q.size();k<s;k++){
            i=q.front();q.pop();
            for(int& j:g[i]){
                if(!visited[j]){
                    visited[j]=true;
                    q.push(j);
                    cnt++;
                }
            }
        }
        l1++;
    }
    return cnt;
}

int main(){
    scanf("%d %d",&n,&l);
    g.assign(n+1, vector<int>());
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&q);
            g[q].push_back(i);
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&q);
        printf("%d\n", bfs(q));
    }
    return 0;
}